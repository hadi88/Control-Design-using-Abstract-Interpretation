//
//  SafeRegion.h
//  Controller Synthesis for Safety
//
//  Created by Hadi Ravanbakhsh on 7/7/14.
//  Copyright (c) 2014 University of Colorado Boulder. All rights reserved.
//

#ifndef __Controller_Synthesis_for_Safety__I_Polyhedron__
#define __Controller_Synthesis_for_Safety__I_Polyhedron__

#include <iostream>
#include <vector>
using namespace std;
class I_Polyhedron{
public:
    vector<vector<double>* >* coefs;
    vector<double>* bounds;
    void validate(int numOfDimensions, string name);
};
#endif /* defined(__Controller_Synthesis_for_Safety__I_Polyhedron__) */
