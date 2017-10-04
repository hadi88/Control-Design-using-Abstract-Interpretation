//
//  AbstractSet.h
//  Controller Synthesizer
//
//  Created by Hadi Ravanbakhsh on 7/15/13.
//  Copyright (c) 2013 Hadi Ravanbakhsh. All rights reserved.
//

#ifndef __Controller_Synthesizer__AbstractSet__
#define __Controller_Synthesizer__AbstractSet__

#include "includes.h"
#include "Transformer.h"
#include "BDD_Node.h"
#include "Drifter.h"

class AbstractSet{
    
public:
    AbstractSet();
    
    AbstractSet(const B_Polyhedron* pIn);
    
    virtual void meet(const B_Polyhedron* pIn) = 0;
    
    // generate the intersection for output
    virtual AbstractSet* meet(const AbstractSet& pIn) const = 0;
    
    virtual bool isEmpty() const = 0;
    
    virtual int getSize() const = 0;
    
    virtual bool contains(const AbstractSet& pIn) const = 0;
    
    virtual bool containsPoly(const B_Polyhedron* pIn) const = 0;
    
    virtual void widen(const AbstractSet& pIn) = 0;
    
    virtual void printPoints() const = 0;
    
    virtual void printConstraints() const = 0;
    
    // Returns the precondition with respect to the transformer
    virtual AbstractSet* backward(const Transformer& tr) const = 0;
    
    // Adds the disturbance and returns the result
    virtual AbstractSet* drift(const Drifter& dr) const = 0;
    
    virtual AbstractSet* clone() const = 0;
    
    // reduce the coefficients of PPL
    virtual void approximate() = 0;
    
    virtual BDD_Node* getBDD() const = 0;
    
    virtual bool isIn(const B_Polyhedron& pIn) const = 0;
    
    virtual void meetWithoutOptimization(B_Polyhedron* pIn) const = 0;

    virtual bool contains(vector<double> point) const = 0;
    
    virtual void meetAndChange(const AbstractSet& pIn) = 0;
    
    virtual ~AbstractSet();
};

#endif /* defined(__Controller_Synthesizer__AbstractSet__) */
