//
//  BDD_Builder.cpp
//  Controller Synthesizer
//
//  Created by Hadi Ravanbakhsh on 1/30/14.
//  Copyright (c) 2014 Hadi Ravanbakhsh. All rights reserved.
//

#include "BDD_Builder.h"
#include "Utilities.h"

BDD_Builder::BDD_Builder(const Problem& problem, map<Annotations, A_Set*>& finalMap
                         , vector<vector<pair<Annotation, Constraint> > >& partitionConstraints)
:problem(problem),finalMap(finalMap), partitionConstraints(partitionConstraints){
    maxTimes.resize(problem.getPSize());
    totalPoly = 0;
    for( map<Annotations, A_Set*>::iterator ii = finalMap.begin(); ii != finalMap.end(); ii++){
        Annotations ann = (*ii).first;
        bool isUseless = false;
        for (int u = 0; u < problem.getPSize(); u++) {
            int t = ann.getAnnotation(u).time;
            if (t == 0) {
                isUseless = true;
            }
            maxTimes[u] = max(maxTimes[u], ann.getAnnotation(u).time);
        }
        if (!isUseless) {
            totalPoly++;
        }
    }
    
}

vector<Constraint> BDD_Builder::createPolyhedron(){
    vector<Constraint> result;
    vector<Constraint> initConst = problem.getSafe().getConstraintsVector();
    
    B_Polyhedron* b = new B_Polyhedron(problem.getNSize());
    
    for(set<Annotation>::iterator it = restrictions.begin(); it != restrictions.end(); it++){
        Annotation an = *it;
        Transformer transformer = problem.getTransformer(an.u);
        if (an.constraint >= problem.getCSize()) {
            for (int c = 0; c < initConst.size(); c++) {
                Constraint cons = initConst[c];
                for (int t = 1; t < an.time; t++) {
                    cons = transformer.backward(cons);
                }
                if (c < an.constraint - problem.getCSize()) {
                    cons = transformer.backward(cons);
                }else if (c == an.constraint - problem.getCSize()) {
                    result.push_back(cons);
                    b->addConstraint(cons);
                    cons = transformer.backward(cons);
                    cons = Utilities::negateInequality(cons, problem.getNSize());
                }
                result.push_back(cons);
                b->addConstraint(cons);
            }
        }else{
            for (int c = 0; c < initConst.size(); c++) {
                Constraint cons = initConst[c];
                for (int t = 1; t < an.time; t++) {
                    cons = transformer.backward(cons);
                }
                if (c <= an.constraint) {
                    cons = transformer.backward(cons);
                }
                result.push_back(cons);
                b->addConstraint(cons);
            }
        }
    }
    return result;
}

bool BDD_Builder::isAcceptable(Annotations ann){
    for(set<Annotation>::iterator it = restrictions.begin(); it != restrictions.end(); it++){
        Annotation an = *it;
        Annotation currentAn(ann.getAnnotation(an.u));
        if (an.constraint >= problem.getCSize()) {
            if (currentAn.time != an.time || currentAn.constraint != an.constraint-problem.getCSize()) {
                return false;
            }
        }else{
            if (currentAn.time < an.time) {
                return false;
            }
            if (currentAn.time == an.time && currentAn.constraint <= an.constraint) {
                return false;
            }
        }
    }
    return true;
}

BDD_Node* BDD_Builder::build(){
    if (totalPoly == 0) {    // only debugging
        return &BDD_Node::REJECTED_LEAF;
    }
    if (totalPoly == 1) {
        return finalMap.begin()->second->cp->getBDD();
    }
    vector<Annotation> restAnns;
    for (int i = 0; i < problem.getPSize(); i++) {
        restAnns.push_back(Annotation(i, 0, 0));
    }
    B_Polyhedron* restPoly = problem.getSafe().clone();
    B_Polyhedron* prevRestPoly = problem.getSafe().clone();
    map<Annotations, A_Set*> inside;
    map<Annotations, A_Set*> outside;
    for (int u = 0; u < problem.getPSize(); u++) {
        inside.clear();
        outside.clear();
        for( map<Annotations, A_Set*>::iterator ii = finalMap.begin(); ii != finalMap.end(); ii++){
            Annotations ann = (*ii).first;
            if (ann.getAnnotation(0).time == 0) {
                continue;
            }
            bool isInside = true;
            for (int i = 0; i < u; i++) {
                if (!(ann.all[i].time == restAnns[i].time && ann.all[i].constraint == restAnns[i].constraint)) {
                    isInside = false;
                    break;
                }
            }
            if (ann.all[u].time < restAnns[u].time || (ann.all[u].time == restAnns[u].time && ann.all[u].constraint <= restAnns[u].constraint)) {
                isInside = false;
            }
            if (isInside) {
                inside[ann] = (*ii).second;
            }else{
                outside[ann] = (*ii).second;
            }
        }
        int t = 0;
        while( t < partitionConstraints[u].size() &&
              (inside.size() >= 0.67 * totalPoly )){
            t++;
            prevRestPoly->addConstraint(partitionConstraints[u][t-1].second);
            restAnns[u] = partitionConstraints[u][t].first;
            restPoly->addConstraint(partitionConstraints[u][t].second);
            map<Annotations, A_Set*> newInside;
            for( map<Annotations, A_Set*>::iterator ii = inside.begin(); ii != inside.end(); ii++){
                Annotations ann = (*ii).first;
                bool isInside = true;
                if (ann.all[u].time < restAnns[u].time || (ann.all[u].time == restAnns[u].time && ann.all[u].constraint <= restAnns[u].constraint)) {
                    isInside = false;
                }
                if (!isInside) {
                    outside[ann] = (*ii).second;
                }else{
                    newInside[ann] = (*ii).second;
                }
            }
            inside.clear();
            inside.insert(newInside.begin(), newInside.end());
        }
        if (t >= partitionConstraints[u].size()
            && inside.size() >= 0.67 * totalPoly) {
            continue;
        }
        if (inside.size() > 0.33 * totalPoly) {
            break;
        }
        delete restPoly;
        restPoly = prevRestPoly->clone();
        Constraint c = Utilities::negateInequality(partitionConstraints[u][t].second, prevRestPoly->getNumOfDimensions());
        restAnns[u] = partitionConstraints[u][t].first;
        restPoly->addConstraint(c);
        
    }
    BDD_Builder tBuilder(problem, inside, partitionConstraints);
    BDD_Builder fBuilder(problem, outside, partitionConstraints);
    
    if (inside.empty() || outside.empty()){
        cout << "debug" << endl;
    }
    BDD_Node* res = new BDD_Node(restPoly->getConstraintsVector(), tBuilder.build(), fBuilder.build());
    return res;
}