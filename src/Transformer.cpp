//
//  Transformer.cpp
//  Controller Synthesizer
//
//  Created by Hadi Ravanbakhsh on 6/7/13.
//  Copyright (c) 2013 Hadi Ravanbakhsh. All rights reserved.
//

#include "Transformer.h"
#include "Utilities.h"

Transformer::Transformer(int size, Mode* mode) {
    this->size = size;
    B = vector<long>(size);
    A = vector<vector<long> >(size);
    vector<double> Bd = vector<double>(size);
    vector<vector<double> > Ad = vector<vector<double> >(size);
    factor = 1;
    inPartition = false;
    
    inPartition = mode->forPartitioning;

    for (int i = 0; i < size; i++) {
        A[i] = vector<long>(size);
        Ad[i] = vector<double>(size);
        for (int j = 0; j < size; j++) {
            Ad[i][j] = mode->A->at(i)->at(j);
            while (abs(round(factor*Ad[i][j]) - factor*Ad[i][j]) > EPSILONE_COEF) {
                factor *= 10;
            }
        }
    }
    for (int i = 0; i < size; i++) {
        Bd[i] = mode->B->at(i);
        while (abs(round(factor*Bd[i]) - factor*Bd[i]) > EPSILONE_COEF) {
            factor *= 10;
        }
    }
    for (int i = 0; i < size; i++) {
        B[i] = (int) round(factor * Bd[i]);
        for (int j = 0; j < size; j++) {
            A[i][j] = (int) round(factor * Ad[i][j]);
        }
    }
    
}

Constraint Transformer::backward(const Constraint& c) const{
    Coefficient constCoef = c.inhomogeneous_term() * factor;
    
    for (int j = 0; j < size; j++) {
        constCoef += B[j] * c.coefficient(Variable(j));
    }
    
    Linear_Expression le ;
    for (int i = 0; i < size; i++) {
        Coefficient coef = Coefficient_zero();
        for (int j = 0; j < size; j++) {
            coef += A[j][i] * c.coefficient(Variable(j));
        }
        le += coef * Variable(i);
    }
    
    Constraint newC;
    if (c.is_equality()) {
        newC = Constraint( le == -constCoef);
    } else if(c.is_nonstrict_inequality()){
        newC = Constraint( le >= -constCoef);
    } else if(c.is_strict_inequality()){
        newC = Constraint( le > -constCoef);
    }
    return newC;
}

B_Polyhedron* Transformer::backward(const B_Polyhedron &pIn) const{

    Constraint_System cs = pIn.getConstraints();
    B_Polyhedron* res = new B_Polyhedron(pIn.getNumOfDimensions());
    
    for (Constraint_System_const_iterator it = cs.begin(); it != cs.end(); it++) {
        Constraint c = *it;
        
        res->addConstraint(backward(c));
    }
    return res;
}

bool Transformer::isInPartition() const{
    return this->inPartition;
}


Transformer::~Transformer(){
}