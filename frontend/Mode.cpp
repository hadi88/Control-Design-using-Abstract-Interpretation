//
//  Mode.cpp
//  Controller Synthesis for Safety
//
//  Created by Hadi Ravanbakhsh on 7/7/14.
//  Copyright (c) 2014 University of Colorado Boulder. All rights reserved.
//

#include "Mode.h"
#include <cstdlib>
void Mode::validate(int numOfDimensions){
    if (A->size() != numOfDimensions || B->size() != numOfDimensions) {
        cerr << "Dynamics of mode " << *name << " is not consistent with number of dimensions (" << numOfDimensions << ")" << endl;
        exit(-1);
    }
    for (vector<vector<double>*>::iterator it = A->begin(); it != A->end(); it++) {
        vector<double>* vec = *it;
        if (vec->size() != numOfDimensions) {
            cerr << "Dynamics of mode " << *name << " is not consistent with number of dimensions (" << numOfDimensions << ")" << endl;
            exit(-1);
        }
    }
}