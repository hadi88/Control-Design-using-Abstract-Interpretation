//
//  Input.cpp
//  Controller Synthesis for Safety
//
//  Created by Hadi Ravanbakhsh on 7/7/14.
//  Copyright (c) 2014 University of Colorado Boulder. All rights reserved.
//

#include "Input.h"
#include <cstring>
#include "../src/Problem.h"
#include "../src/T_Polyhedron.h"
#include "../src/Drifter.h"
#include "../src/Utilities.h"
#include "../src/Problem.h"
#include "../src/CCI.h"
#include "../src/BDD_Builder.h"

vector<Mode*>* Input::getModes(vector<string*>* names){
    set<Mode*> result;
    for (vector<string*>::iterator itn = names->begin(); itn != names->end(); itn++) {
        string* name = *itn;
        bool found = false;
        for (vector<Mode*>::iterator it = (this->modes)->begin(); it != (this->modes)->end(); it++) {
            Mode* m = *it;
            if (strcmp(m->name->c_str(), name->c_str()) == 0){
                result.insert(m);
                m->forPartitioning = true;
                found = true;
                break;
            }
        }
        if (! found){
            cerr << "Mode with name " + *name + " is not defined" << endl;
            exit(-1);
        }
    }
    vector<Mode*>* retVal = new vector<Mode*>();
    for (set<Mode*>::iterator it = result.begin(); it != result.end(); it++) {
        retVal->push_back(*it);
    }
    return retVal;
}

void Input::validate(){
    if (numOfDimensions < 1 ) {
        cerr << "Number of dimensions should be a positive integer" << endl;
        exit(-1);
    }
    if (modes->size() < 2) {
        cerr << "At least 2 modes are needed for synthesis" << endl;
        exit(-1);
    }
    set<string> names;
    for (vector<Mode*>::iterator it = modes->begin(); it != modes->end(); it++) {
        (*it)->validate(numOfDimensions);
        for (set<string>::iterator itS = names.begin(); itS != names.end(); itS++) {
            if (strcmp((*itS).c_str(), (*it)->name->c_str()) == 0) {
                cerr << "Mode with name " << *itS << " is defined more than once" << endl;
                exit(-1);
            }
        }
        names.insert(*((*it)->name));
    }
    safeRegion->validate(numOfDimensions, "safe region");
    disturbance->validate(numOfDimensions, "disturbance");
    partition->pgpModes = getModes(partition->pgpModesNames);
    partition->validate(numOfDimensions);
}

void Input::processProblem(){
    cout.precision(15);
    validate();
    Problem p(this);
    T_Polyhedron::init(p.getNSize());
    
    CCI complementaryOfControlledInvariant(p);
    pair<map<Annotations, A_Set*> , vector<vector<pair<Annotation, Constraint> > > >& result
    = complementaryOfControlledInvariant.solve();
    cout << "--\nBDD:";
    cout << endl;
    const double startTime = clock();
    BDD_Builder bddBuilder(p, result.first, result.second);
    BDD_Node* bdd = bddBuilder.build();
    cout << "bdd - time used: ";
    cout << ((clock()-startTime)/CLOCKS_PER_SEC);
    cout << endl;
    cout << "Height: ";
    cout << bdd->getHeight();
    cout << "\nWorst-case Number of Inequalities: ";
    cout << bdd->getNumOfOperations();
    cout << endl;
    
    Utilities::o.open((Utilities::outputFolder+"/IsInDisturbanceInvariant.m").c_str());
    Utilities::print("function [ result ] = IsInDisturbanceInvariant( X )\n");
    vector<Constraint> safeC = p.getSafe().getConstraintsVector();
    Utilities::print("if ( ~(");
    Utilities::printConstraint(safeC[0], p.getNSize());
    for (int i = 1; i < safeC.size(); i++) {
        Utilities::print(") || ~(");
        Utilities::printConstraint(safeC[i], p.getNSize());
    }
    Utilities::print(") ) \n");
    Utilities::print("\tresult = 1;\n\treturn;\n");
    Utilities::print("end\n");
    bdd->generateCode("", p.getNSize());
    Utilities::print("end\n");
    Utilities::o.close();
    if (bdd != &BDD_Node::ACCEPTED_LEAF && bdd != &BDD_Node::REJECTED_LEAF)
        delete bdd;
    exit(0);
    
}
