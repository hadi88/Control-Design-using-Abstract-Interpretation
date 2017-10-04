//
//  PartitioningMethod.h
//  Controller Synthesis for Safety
//
//  Created by Hadi Ravanbakhsh on 7/7/14.
//  Copyright (c) 2014 University of Colorado Boulder. All rights reserved.
//

#ifndef __Controller_Synthesis_for_Safety__PartitioningMethod__
#define __Controller_Synthesis_for_Safety__PartitioningMethod__

#include <iostream>
#include <vector>
#include "Mode.h"
using namespace std;
class PartitioningMethod{
public:
    vector<Mode*>* pgpModes;
    vector<string*>* pgpModesNames;
    void validate(int numOfDimensions);
};
#endif /* defined(__Controller_Synthesis_for_Safety__PartitioningMethod__) */
