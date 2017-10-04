//
//  B_Polyhedron.h
//  Controller Synthesizer
//
//  Created by Hadi Ravanbakhsh on 6/7/13.
//  Copyright (c) 2013 Hadi Ravanbakhsh. All rights reserved.
//

#ifndef __Controller_Synthesizer__B_Polyhedron__
#define __Controller_Synthesizer__B_Polyhedron__

#include "includes.h"
#include "../frontend/I_Polyhedron.h"

// Bounded Polyhedron (An interface for PPL)
class B_Polyhedron{
private:
    int numOfDimensions;
protected:
    NNC_Polyhedron p;
public:
    B_Polyhedron(int numOfDimensions, I_Polyhedron* inPoly);
    B_Polyhedron(int numOfDimensions);
    B_Polyhedron(const B_Polyhedron& bp);
    
    // check if it's bounded
    bool isValid() const;
    bool isEmpty() const;
    void addConstraint(Constraint c);
    Constraint getConstraint(int index);
    vector<Constraint> getConstraintsVector();

    // the result must be a polyhedron and pIn is inside this
    Constraint getSeparator(const B_Polyhedron& pIn) const;
    
    Constraint maximize(Linear_Expression le, long factor) const;
    Coefficient maximizeOffset(Linear_Expression le, long factor) const;
    void meet(const B_Polyhedron& pIn);
    void meetWithoutOptimization(const B_Polyhedron& pIn);
    B_Polyhedron* join(const B_Polyhedron& pIn);
    bool contains(const B_Polyhedron& pIn) const;
    
    // setter for the polyhedron
    void setTo(const B_Polyhedron& pIn);
    
    // print Matlab command for drawing the polyhedron in 2D
    void printPoints() const;
    Constraint_System getConstraints() const;
    int getNumOfDimensions() const;
    void printConstraints() const;
    
    // approximate the coefficients s. t. the coefficients remain small
    B_Polyhedron* approximate() const;
    
    B_Polyhedron* clone() const;
    bool contains(vector<double> point) const;
    ~B_Polyhedron();
};



#endif /* defined(__Controller_Synthesizer__B_Polyhedron__) */
