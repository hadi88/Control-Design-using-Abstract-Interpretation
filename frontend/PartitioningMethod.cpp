//
//  PartitioningMethod.cpp
//  Controller Synthesis for Safety
//
//  Created by Hadi Ravanbakhsh on 7/7/14.
//  Copyright (c) 2014 University of Colorado Boulder. All rights reserved.
//

#include "PartitioningMethod.h"

void PartitioningMethod::validate(int numOfDimensions){
    
    if (pgpModes->empty()) {
            cerr << "At least one mode should be chosen for precondition-guided partitioning" << endl;
            exit(-1);
    }
}