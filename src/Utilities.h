//
//  Utilities.h
//  Controller Synthesizer
//
//  Created by Hadi Ravanbakhsh on 6/10/13.
//  Copyright (c) 2013 Hadi Ravanbakhsh. All rights reserved.
//

#ifndef __Controller_Synthesizer__Utilities__
#define __Controller_Synthesizer__Utilities__

#define NORMAL_STR "normal"
#define EQUALITY_STR "equality"
#define STRICT_STR "strict"

#include "includes.h"

class Utilities{
public:
    static ofstream o;
    template<typename T> static void print(T s);
    static string outputFolder;

    static Constraint negateInequality(Constraint c, int numOfDimensions);
    static void printConstraint(Constraint c, int numOfDimensions);
    static void printConstraintByENDL(Constraint c, int numOfDimensions);
    static bool checkSatisfaction(Constraint_System c, int numOfDimensions, double* point);
    static Constraint clone(const Constraint& c, int numOfDimensions);
    static int getIntFactor(vector<double> inv);
    static string getRelationType(const Constraint& c);
};

#endif /* defined(__Controller_Synthesizer__Utilities__) */
