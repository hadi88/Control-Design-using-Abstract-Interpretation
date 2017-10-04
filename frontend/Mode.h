//
//  Mode.h
//  Controller Synthesis for Safety
//
//  Created by Hadi Ravanbakhsh on 7/7/14.
//  Copyright (c) 2014 University of Colorado Boulder. All rights reserved.
//

#ifndef __Controller_Synthesis_for_Safety__Mode__
#define __Controller_Synthesis_for_Safety__Mode__

#include <iostream>
#include <vector>
#include "../src/includes.h"
using namespace std;
class Mode{
public:
    bool forPartitioning;
    string* name;
    vector<vector<double>* >* A;
    vector<double>* B;
    void validate(int numOfDimensions);
};
#endif /* defined(__Controller_Synthesis_for_Safety__Mode__) */
