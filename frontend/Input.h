//
//  Input.h
//  Controller Synthesis for Safety
//
//  Created by Hadi Ravanbakhsh on 7/7/14.
//  Copyright (c) 2014 University of Colorado Boulder. All rights reserved.
//

#ifndef __Controller_Synthesis_for_Safety__Input__
#define __Controller_Synthesis_for_Safety__Input__

#include <iostream>
#include <vector>
using namespace std;
#include "Mode.h"
#include "I_Polyhedron.h"
#include "PartitioningMethod.h"

class Input{
public:
    int numOfDimensions;
    vector<Mode*>* modes;
    I_Polyhedron* safeRegion;
    I_Polyhedron* disturbance;
    PartitioningMethod* partition;
    
    vector<Mode*>* getModes(vector<string*>* name);
    void processProblem();
    void validate();
};
#endif /* defined(__Controller_Synthesis_for_Safety__Input__) */
