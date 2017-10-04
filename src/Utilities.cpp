//
//  Utilities.cpp
//  Controller Synthesizer
//
//  Created by Hadi Ravanbakhsh on 6/10/13.
//  Copyright (c) 2013 Hadi Ravanbakhsh. All rights reserved.
//

#include "Utilities.h"

ofstream Utilities::o;
string Utilities::outputFolder;
template<typename T> void Utilities::print(T s){
    Utilities::o << s;
}

string Utilities::getRelationType(const Constraint& c){
    if (c.is_strict_inequality()) {
        return STRICT_STR;
    } else if (c.is_equality()){
        return EQUALITY_STR;
    }
    return NORMAL_STR;
}

Constraint Utilities::negateInequality(Constraint c, int numOfDimensions){
    Coefficient constCoef = c.inhomogeneous_term();
    Linear_Expression le = c.coefficient(Variable(0)) * (Variable(0));
    for (int i = 1; i < numOfDimensions; i++) {
        le += c.coefficient(Variable(i)) * (Variable(i));
    }
    if (c.is_nonstrict_inequality()) {
        return Constraint(le < -constCoef);
    } else {
        return Constraint(le <= -constCoef);
    }
}

void Utilities::printConstraint(Constraint c, int numOfDimensions){
    for (int i = 0; i < numOfDimensions; i++) {
        Coefficient coef = c.coefficient(Variable(i));
        Utilities::print(coef.get_d());
        Utilities::print("*X(");
        Utilities::print(i+1);
        Utilities::print(")");
        Utilities::print(((i == numOfDimensions - 1)?"":" + "));
    }
    
    Utilities::print(
                     (c.is_equality()? " == " : (c.is_nonstrict_inequality()?" >= ":" >  ")));
    Utilities::print(-c.inhomogeneous_term().get_d());
}

void Utilities::printConstraintByENDL(Constraint c, int numOfDimensions){
    printConstraint(c, numOfDimensions);
    Utilities::print("\n");
}

bool Utilities::checkSatisfaction(Constraint_System cs, int numOfDimensions, double* point){
    for (Constraint_System_const_iterator it = cs.begin(); it != cs.end(); it++) {
        Constraint c = (*it);
        double sum = 0;
        for (int d = 0; d < numOfDimensions; d++) {
            sum = sum + c.coefficient(Variable(d)).get_si() * point[d];
        }
        double expected = -c.inhomogeneous_term().get_si();
        if (sum < expected - (EPSILONE_BOUNDARY*abs(expected))) {
            return false;
        }
    }
    return true;
}

Constraint Utilities::clone(const Constraint& c, int numOfDimensions){
    Coefficient constCoef = c.inhomogeneous_term();
    Linear_Expression le = c.coefficient(Variable(0)) * (Variable(0));
    for (int i = 1; i < numOfDimensions; i++) {
        le += c.coefficient(Variable(i)) * (Variable(i));
    }
    
    Constraint newC;
    if (c.is_equality()) {
        newC = Constraint(le == -constCoef);
    }else if (c.is_nonstrict_inequality()) {
        newC = Constraint(le >= -constCoef);
    }else if (c.is_strict_inequality()){
        newC = Constraint(le > -constCoef);
    }
    for (int i = 0; i < numOfDimensions; i++) {
        if (c.coefficient(Variable(i)) != newC.coefficient(Variable(i))) {
            cout << "error" << endl;
        }
    }
    return newC;
}

// Find an integer factor "coef" s.t. coef * inv[i] is integer
int Utilities::getIntFactor(vector<double> inv){
    int coef = 1;
    for (vector<double>::iterator it = inv.begin(); it != inv.end(); it++) {
        double d = *it;
        double num = d * coef;
        double error = abs((long)(num) - num);
        if (error > 0.5) {
            error = 1 - error;
        }
        while  ( error > EPSILONE_COEF) {
            coef *= 10;
            num *= 10;
            error = abs((long)(num) - num);
            if (error > 0.5) {
                error = 1 - error;
            }
        }
    }
    return coef;
}
