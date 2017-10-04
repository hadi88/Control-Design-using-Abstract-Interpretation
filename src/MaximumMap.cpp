//
//  MaximumMap.cpp
//  Controller Synthesizer
//
//  Created by Hadi Ravanbakhsh on 6/14/13.
//  Copyright (c) 2013 Hadi Ravanbakhsh. All rights reserved.
//

#include "MaximumMap.h"
#include "Utilities.h"

MaximumMap::MaximumMap(Problem& problem): problem(problem){
    qSize = problem.getQSize();
    pSize = problem.getPSize();
    cSize = 0;
    rests.resize(pSize);
    constraintsList.resize(pSize);
    neighbourPreSegments.resize(qSize);
    neighboursPreComputedSet.resize(qSize);
    fullPreAnns.resize(qSize);
    for (int u = 0; u < pSize; u++) {
        rests[u] = problem.getSafe().clone();
    }
}

void MaximumMap::addConstraint(B_Polyhedron& constraint, Constraint cons){
    vector<Annotation> all;
    for (int u = 0; u < pSize; u++){
        Annotation ann(u, cSize, 0);
        all.push_back(ann);
        annToPoly[ann] =  new B_Polyhedron(constraint);
        constraintsList[u].push_back(make_pair(ann, cons));
    }
    annToNotDrifted[all] = new B_Polyhedron(constraint);
    cSize++;
}

void MaximumMap::findNewSegments(int u, int c, int t){
    Annotation ann(u, c, t);
    if (pSize == 1) {
        vector<Annotation> all;
        Annotation ann = Annotation(u, c, t);
        all.push_back(ann);
        annToNotDrifted[Annotations(all)] = annToPoly[ann]->clone();
        return;
    }
    vector<vector<Annotation > > possibles;
    map<int, int> uMap;
    int ucc = 0;
    for (int uc = 0 ; uc < pSize; uc++) {
        if (u == uc) {
            continue;
        }
        possibles.push_back(vector<Annotation>());
        B_Polyhedron* rest = annToPoly[ann]->clone();
        int offSet = cSize;
        for (vector<pair<Annotation, Constraint> >::iterator it = constraintsList[uc].begin()+offSet;
             it != constraintsList[uc].end(); it++) {
            B_Polyhedron* temp = rest->clone();
            temp->addConstraint(it->second);
            if (temp->isEmpty()) {
                possibles[ucc].push_back(it->first);
                uMap[ucc] = uc;
                delete temp;
                break; // we can remove it from constraint list here
            }
            if (!temp->contains(*rest)) {
                possibles[ucc].push_back(it->first);
                uMap[ucc] = uc;
            }
            delete rest;
            rest = temp;
        }
        delete rest;
        ucc++;
    }
    
    int maxU = (int) uMap.size();
    if (maxU < pSize - 1)
        return;
    
    stack<B_Polyhedron*> polyStack;
    polyStack.push(annToPoly[ann]->clone());
    stack<Annotations> annStack;
    annStack.push(Annotations(vector<Annotation>(pSize)).getUpdated(ann));
    
    vector<vector<Annotation>::iterator> itrStack;
    vector<int> counterStack;
    for (int u = 0; u < maxU; u++) {
        counterStack.push_back(0);
        itrStack.push_back(possibles[u].begin());
    }
    int currentU = 0;
    while (currentU >= 0) {
        if (currentU == maxU) {
            annToNotDrifted[annStack.top()] = polyStack.top();
            polyStack.pop();
            annStack.pop();
            currentU--;
            if (itrStack[currentU] != possibles[currentU].end()) {
                itrStack[currentU]++;
            }
            counterStack[currentU]++;
        }else if(counterStack[currentU] < possibles[currentU].size()){
            B_Polyhedron* temp = polyStack.top()->clone();
            B_Polyhedron* ptrMax = annToPoly[*(itrStack[currentU])];
            if (ptrMax != NULL) {
                temp->meet(*ptrMax);
            }else{
                temp->addConstraint(Variable(0)*0 > 1);
            }
            if (!temp->isEmpty()) {
                Annotations newAnn = annStack.top().getUpdated(*(itrStack[currentU]));
                polyStack.push(temp);
                annStack.push(newAnn);
                currentU++;
            }else{
                delete temp;
                counterStack[currentU]++;
                if (itrStack[currentU] != possibles[currentU].end()) {
                    itrStack[currentU]++;
                }
            }
            
        } else {
            counterStack[currentU] = 0;
            itrStack[currentU] = possibles[currentU].begin();
            delete polyStack.top();
            polyStack.pop();
            annStack.pop();
            if (currentU > 0){
                if (itrStack[currentU-1] != possibles[currentU].end()) {
                    itrStack[currentU-1]++;
                }
                counterStack[currentU-1]++;
            }
            currentU--;
        }
    }
    
}

bool MaximumMap::updateMap(Annotation ann){
    int lastTime = (int) ucToMaxTime[ann.u];
    if (lastTime < ann.time) {
        for (int t = lastTime; t < ann.time; t++) {
            for (int c = 0; c < cSize; c++) {
                vector<pair<Annotation, Constraint> >::iterator it = constraintsList[ann.u].end();
                it--;
                while (it->first.time > t || (it->first.time == t && it->first.constraint > c)) {
                    it--;
                }
                if (it->first.time != t || it->first.constraint != c) {
                    continue;
                }
                Constraint cons = Utilities::negateInequality(it->second, problem.getNSize());
                Constraint previousC = problem.getTransformer(ann.u).backward(cons);
                Constraint prevC = problem.getDrifter().drift(previousC);
                B_Polyhedron* temp = new B_Polyhedron(problem.getNSize());
                temp->addConstraint(prevC);
                temp->meet(problem.getSafe());
                if (temp->isEmpty()) {
                    delete temp;
                    continue;
                }
                B_Polyhedron* temp2 = temp->approximate();
                temp2->meet(problem.getSafe());
                prevC = Utilities::negateInequality(problem.getSafe().getSeparator(*temp2), problem.getNSize());
                delete temp;
                delete temp2;
                prevC = Utilities::negateInequality(prevC, problem.getNSize());
                temp = rests[ann.u]->clone();
                temp->addConstraint(Utilities::negateInequality(prevC, problem.getNSize()));
                if (temp->isEmpty()) {
                    delete temp;
                    continue;
                } else{
                    annToPoly[Annotation(ann.u, c, t+1)] = temp;
                    findNewSegments(ann.u, c, t+1);
                    rests[ann.u]->addConstraint(prevC);
                    constraintsList[ann.u].push_back(make_pair(Annotation(ann.u, c, t+1),prevC));
                }
            }
        }
        ucToMaxTime[ann.u] = ann.time;
    }
    return true;
}

void MaximumMap::updatePreNeighbours(int preU, Annotations ann){

    if (neighboursPreComputedSet[preU].find(ann) == neighboursPreComputedSet[preU].end()) {
        neighboursPreComputedSet[preU].insert(ann);
        
        B_Polyhedron* b = getMap(ann);
        B_Polyhedron* bTransfered = problem.getTransformer(preU).backward(*b);
        Annotation an = ann.all[preU];
        B_Polyhedron* initPoly = problem.getDrifter().drift(*bTransfered);
        initPoly->meet(problem.getSafe());
        delete bTransfered;
        int offSet = cSize;
        vector<vector<Annotation > > possibles;
        for (int uc = 0 ; uc < pSize; uc++) {
            possibles.push_back(vector<Annotation>());
            B_Polyhedron* rest = initPoly->clone();
            for (vector<pair<Annotation, Constraint> >::iterator it = constraintsList[uc].begin()+offSet;
                 it != constraintsList[uc].end(); it++) {
                B_Polyhedron* temp = rest->clone();
                temp->addConstraint(it->second);
                if (temp->isEmpty()) {
                    possibles[uc].push_back(it->first);
                    delete temp;
                    break; // we can remove it from constraint list here
                }
                if (!temp->contains(*rest)) {
                    possibles[uc].push_back(it->first);
                }
                delete rest;
                rest = temp;
            }
            delete rest;
        }
        
        stack<B_Polyhedron*> polyStack;
        polyStack.push(initPoly->clone());
        stack<Annotations> annStack;
        annStack.push(Annotations(vector<Annotation>(pSize)));
        
        vector<vector<Annotation>::iterator> itrStack;
        vector<int> counterStack;
        for (int u = 0; u < pSize; u++) {
            counterStack.push_back(0);
            itrStack.push_back(possibles[u].begin());
        }
        int currentU = 0;
        while (currentU >= 0) {
            if (currentU == pSize) {
                neighbourPreSegments[preU].insert(make_pair(ann,annStack.top()));
                delete polyStack.top();
                polyStack.pop();
                annStack.pop();
                currentU--;
                if (itrStack[currentU] != possibles[currentU].end()) {
                    itrStack[currentU]++;
                }
                counterStack[currentU]++;
            }else if(counterStack[currentU] < possibles[currentU].size()){
                B_Polyhedron* temp = polyStack.top()->clone();
                B_Polyhedron* ptrMax = annToPoly[*(itrStack[currentU])];
                if (ptrMax != NULL) {
                    temp->meet(*ptrMax);
                }else{
                    temp->addConstraint(Variable(0)*0 > 1);
                }
                if (!temp->isEmpty()) {
                    Annotations newAnn = annStack.top().getUpdated(*(itrStack[currentU]));
                    polyStack.push(temp);
                    annStack.push(newAnn);
                    currentU++;
                }else{
                    delete temp;
                    counterStack[currentU]++;
                    if (itrStack[currentU] != possibles[currentU].end()) {
                        itrStack[currentU]++;
                    }
                }
                
            } else {
                counterStack[currentU] = 0;
                itrStack[currentU] = possibles[currentU].begin();
                delete polyStack.top();
                polyStack.pop();
                annStack.pop();
                if (currentU > 0){
                    if (itrStack[currentU-1] != possibles[currentU].end()) {
                        itrStack[currentU-1]++;
                    }
                    counterStack[currentU-1]++;
                }
                currentU--;
            }
        }
        delete initPoly;
    }
    
}

B_Polyhedron* MaximumMap::getMap(Annotations ann){
    if (annToNotDrifted.find(ann) != annToNotDrifted.end()) {
        return annToNotDrifted[ann];
    }
    return NULL;
}

set<Annotations> MaximumMap::getPreNeighbours(int u, Annotations ann){
    
    set<Annotations> result;
    for (multimap<Annotations, Annotations>::iterator it=neighbourPreSegments[u].equal_range(ann).first;
         it!=neighbourPreSegments[u].equal_range(ann).second; ++it){
        result.insert((*it).second);
    }
    return result;
}

set<Annotations> MaximumMap::getAll(){
    
    set<Annotations> result;
    for (map<Annotations, B_Polyhedron*>::iterator it=annToNotDrifted.begin();
         it!=annToNotDrifted.end(); ++it){
        result.insert((*it).first);
    }
    return result;
}


B_Polyhedron* MaximumMap::getMap(Annotation an){
    return annToPoly[Annotation(an.u, an.constraint, an.time)];
}


MaximumMap::~MaximumMap(){
    for (map<Annotation, B_Polyhedron*>::iterator it = annToPoly.begin(); it != annToPoly.end(); it++) {
        delete it->second;
    }
    for (map<Annotations, B_Polyhedron*>::iterator it = annToNotDrifted.begin(); it != annToNotDrifted.end(); it++){
        delete it->second;
    }
    for (int u = 0; u < pSize; u++) {
        delete rests[u];
    }
}
