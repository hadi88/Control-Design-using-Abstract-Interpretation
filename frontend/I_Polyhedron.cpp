//
//  I_Polyhedron.cpp
//  Controller Synthesis for Safety
//
//  Created by Hadi Ravanbakhsh on 7/7/14.
//  Copyright (c) 2014 University of Colorado Boulder. All rights reserved.
//

#include "I_Polyhedron.h"

void I_Polyhedron::validate(int numOfDimensions, string name){
    string err = "Inconsistency in coefficients and bounds of polyhedron defining the " + name;
    if (coefs->size() != bounds->size()) {
        cerr << err << endl;
        exit(-1);
    }
    
    for (vector<vector<double>*>::iterator it = coefs->begin(); it != coefs->end(); it++) {
        if ((*it)->size() != numOfDimensions) {
            cerr << err << endl;
            exit(-1);
        }
    }
}