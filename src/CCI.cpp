//
//  CCI.cpp
//  Controller Synthesizer
//
//  Created by Hadi Ravanbakhsh on 6/10/13.
//  Copyright (c) 2013 Hadi Ravanbakhsh. All rights reserved.
//

#include "CCI.h"
#include "Utilities.h"


CCI::CCI(Problem& problem): problem(problem){
    
    maxMap = new MaximumMap(problem);
    oldPres.resize(problem.getQSize());
    B_Polyhedron rest = B_Polyhedron(problem.getNSize());
    
    int i = 0;
    Constraint_System cs = problem.getSafe().getConstraints();
    for (Constraint_System_const_iterator it = cs.begin(); it != cs.end(); it++) {
        Constraint c = *it;
        B_Polyhedron newSet = B_Polyhedron(rest);
        Constraint negateC = Utilities::negateInequality(c, problem.getNSize());
        newSet.addConstraint(negateC);
        if (!newSet.isEmpty()) {
            
            B_Polyhedron* bpCopy = newSet.clone();
            T_Polyhedron* cNewSet = new T_Polyhedron(bpCopy);
            
            vector<Annotation> initAnnotationList(problem.getPSize());
            for (int post = 0; post < problem.getPSize(); post++) {
                initAnnotationList[post] = (Annotation(post, i, 0));
            }
            Annotations initAnnotations(initAnnotationList);
            A_Set* newASet = new A_Set(cNewSet, initAnnotations);
            maxMap->annToNotDrifted[initAnnotations] = bpCopy->clone();
            newMap[newASet->annotations] = newASet;
            oldMap[newASet->annotations] = newASet;
            maxMap->addConstraint(*bpCopy, c);
        }
        rest.addConstraint(c);
        i++;
    }
}

pair<map<Annotations, A_Set*> , vector<vector<pair<Annotation, Constraint> > > > & CCI::solve(){
    numOfIterations = 0;
    totalNumberOfPolyhedra = problem.getCSize();
    const double startTime = clock();
    for (int u = 0; u < problem.getPSize(); u++) {
        maxMap->updateMap(Annotation(u, problem.getCSize(), CCI::maxItr));
    }
    cout << "total # segments: ";
    cout << (int) maxMap->getAll().size();
    cout << "\n--" << endl;
    do{
        hasChanged = false;
        iterate();
        numOfIterations++;
        int numOfPoly = 0;
        
        for( map<Annotations, A_Set*>::iterator ii=oldMap.begin(); ii!=oldMap.end(); ++ii){
            numOfPoly += ((*ii).second->cp)->getSize();
        }
        cout << "number of polyhedra for " << numOfIterations << " th iteration: ";
        cout << numOfPoly << endl;
        cout << "time used so far : ";
        cout << (clock()-startTime)/CLOCKS_PER_SEC << endl << endl;
    }while (hasChanged);
    
    const double endTime = clock();
    cout << "--" << endl;
    cout << "time used: ";
    cout << (endTime-startTime)/CLOCKS_PER_SEC;
    cout << "\n";
    cout << "num of iterations: ";
    cout << numOfIterations;
    cout << "\n";
    cout << "number of segments: ";
    cout << (int) maxMap->getAll().size();
    cout << endl;
    cout << "number of non-empty segments: ";
    cout << (int) oldMap.size();
    cout << "\n";
    //cout << "number of full segments: ";
    //cout << (int) maxMap->fullAnns.size();
    //cout << endl;
    
    int i = 0;
    if (problem.getNSize() == 2){
        Utilities::o.open((Utilities::outputFolder+"/draw.m").c_str());
        Utilities::print("function draw()\n");
        for( map<Annotations, A_Set*>::iterator ii=oldMap.begin(); ii!=oldMap.end(); ++ii, i++){
            A_Set* p =(*ii).second;
            Annotations ann = (*ii).first;
            p->cp->printPoints();
        }
        Utilities::print("end\n\n\n");
        Utilities::o.close();
    }
    deallocate();
    
    cciResult = make_pair(oldMap, maxMap->constraintsList);
    return cciResult;
}

void CCI::iterate(){
    
    
    // calculate for new found polyhedra
    //          1. precondition
    //          2. maximum polyhedra for pre-segment
    calculateNewPresAndMax();
    cout << "preconditions of " << newMap.size() << " polyhedra calculated" << endl;
    newMap.clear();
    calculateNewPolyhera();
}



void CCI::calculateNewPresAndMax(){
    narrowedChoices.clear();
    int counter = 0;
    for( map<Annotations, A_Set*>::iterator ii=newMap.begin(); ii!=newMap.end(); ++ii){
        A_Set* p = (*ii).second;
        counter++;
        for (int u = 0; u < problem.getQSize(); u++) {
            
            AbstractSet* cpNotDrifted = (p->cp)->backward(problem.getTransformer(u));
            AbstractSet* cp = cpNotDrifted->drift(problem.getDrifter());
            delete cpNotDrifted;
            cp->meet(&problem.getSafe());
            if (cp->isEmpty()) {
                delete cp;
                continue;
            }
            maxMap->updatePreNeighbours(u, p->annotations);
            set<Annotations> segments = maxMap->getPreNeighbours(u, p->annotations);
            for (set<Annotations>::iterator it = segments.begin(); it != segments.end(); it++) {
                if (maxMap->fullPreAnns[u].find(*it) != maxMap->fullPreAnns[u].end()) {
                    continue;
                }
                B_Polyhedron* max = maxMap->getMap(*it);
                AbstractSet* newCP = cp->clone();
                newCP->meet(max);
                if (newCP->isEmpty()) {
                    delete newCP;
                    continue;
                }
                narrowedChoices.insert(*it);
                if (oldPres[u].find(*it) != oldPres[u].end()) {
                    newCP->widen(*(oldPres[u][*it]->cp));
                    newCP->meet(max);
                    delete oldPres[u][*it];
                }
                A_Set* temp = new A_Set(newCP, *it);
                oldPres[u][*it] = temp;
                if (oldPres[u][*it]->cp->containsPoly(max)) {
                    maxMap->fullPreAnns[u].insert(*it);
                }
            }
            delete cp;
        }
        if (problem.getNSize() > 3) {
            cout << "preconditions of " << counter << " polyhedra (of " << newMap.size() << ") is calculated" << endl;
        }
        
    }
}



void CCI::calculateNewPolyhera(){
    
    // find exactly getPost(from).size() precondition with different u's
    // s.t. their intersection is not empty
    
    
    for (set<Annotations>::iterator it = narrowedChoices.begin(); it != narrowedChoices.end(); it++) {
        Annotations ann = *it;
        bool isApplicable = true;
        for (int u = 0; u < problem.getQSize(); u++) {
            if (oldPres[u].find(ann) == oldPres[u].end()) {
                isApplicable = false;
                break;
            }
        }
        if (!isApplicable) {
            continue;
        }
        AbstractSet* init = oldPres[0][ann]->cp->clone();
        for (int u = 1; u < problem.getQSize(); u++) {
            init->meetAndChange(*(oldPres[u][ann]->cp));
            if (init->isEmpty()) {
                break;
            }
        }
        if (init->isEmpty()) {
            delete init;
            continue;
        }
        processNewPolyhedron(new A_Set(init, ann));
    }
}

void CCI::processNewPolyhedron(A_Set *toAddPoly){
    
    Annotations ann = toAddPoly->annotations;
    
    if (maxMap->fullAnns.find(ann) != maxMap->fullAnns.end()) {
        delete toAddPoly;
        return;
    }
    B_Polyhedron* max = maxMap->getMap(ann);
    toAddPoly->cp->meet(max);
    if (newMap.find(ann) != newMap.end()) {
        toAddPoly->cp->widen(*newMap[ann]->cp);
        toAddPoly->cp->meet(max);
        delete newMap[ann];
    }else if (oldMap.find(ann) != oldMap.end()){
        if (oldMap[ann]->cp->contains(*toAddPoly->cp)) {
            delete toAddPoly;
            return;
        }
        hasChanged = true;
        toAddPoly->cp->widen(*oldMap[ann]->cp);
        toAddPoly->cp->meet(max);
        delete oldMap[ann];
    }else{
        hasChanged = true;
        totalNumberOfPolyhedra += toAddPoly->cp->getSize();
    }
    newMap[ann] = toAddPoly;
    oldMap[ann] = toAddPoly;
    
    if (oldMap[ann]->cp->containsPoly(max)) {
        maxMap->fullAnns.insert(ann);
    }
}

void CCI::deallocate(){
    for (int u = 0; u < problem.getQSize(); u++) {
        map<Annotations, A_Set* >  uMap = oldPres[u];
        for(map<Annotations, A_Set* >::iterator ii=uMap.begin(); ii!=uMap.end(); ++ii){
            delete (*ii).second;
        }
        uMap.clear();
        
    }
    newMap.clear();
}


CCI::~CCI(){
    for (map<Annotations, A_Set*>::iterator it = oldMap.begin(); it != oldMap.end(); it++ ) {
        delete it->second;
    }
}
