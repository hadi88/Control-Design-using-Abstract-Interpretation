//
//  Drifter.cpp
//  Controller Synthesizer
//
//  Created by Hadi Ravanbakhsh on 2/19/14.
//  Copyright (c) 2014 Hadi Ravanbakhsh. All rights reserved.
//

#include "Drifter.h"
#include "Utilities.h"

Drifter::Drifter(int size, I_Polyhedron* disturbance): b(size, disturbance) {
    this->size = size;
}
B_Polyhedron* Drifter::getB(){
    return b.clone();
}
Constraint Drifter::drift(const Constraint& c) const{
    
    long factor = 100;
    Linear_Expression le;
    for (int i = 0; i < size; i++) {
        le -= c.coefficient(Variable(i)) * Variable(i);
    }
    Coefficient shift = b.maximizeOffset(-le, factor);
    Coefficient constCoef = (factor * c.inhomogeneous_term()) + shift;
    return Constraint( -factor * le > -constCoef);
}


B_Polyhedron* Drifter::drift(const B_Polyhedron &pIn) const{
    Constraint_System cs = pIn.getConstraints();
    B_Polyhedron* res = new B_Polyhedron(pIn.getNumOfDimensions());
    
    for (Constraint_System_const_iterator it = cs.begin(); it != cs.end(); it++) {
        Constraint c = *it;
        Constraint newC = drift(c);
        res->addConstraint(newC);
    }
    return res;
}

Drifter::~Drifter(){
}
