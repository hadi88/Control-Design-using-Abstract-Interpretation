//
//  Transformer.h
//  Controller Synthesizer
//
//  Created by Hadi Ravanbakhsh on 6/7/13.
//  Copyright (c) 2013 Hadi Ravanbakhsh. All rights reserved.
//

#ifndef __Controller_Synthesizer__Transformer__
#define __Controller_Synthesizer__Transformer__

#include "includes.h"
#include "B_Polyhedron.h"
#include "../frontend/Input.h"

class Transformer{
private:
    // number of dimensions
    int size;
    // factor is for making integer coefficient
    long factor;
    bool inPartition;
    // X(t+1) = A X(t) + B
    vector<vector<long> > A;
    vector<long> B;

public:
    Transformer(int size, Mode* mode);
    // compute precondition of pIn
    B_Polyhedron* backward(const B_Polyhedron& pIn) const;
    // compute constraint's precondition
    Constraint backward(const Constraint& c) const;
    bool isInPartition() const;
    ~Transformer();
};


#endif /* defined(__Controller_Synthesizer__Transformer__) */
