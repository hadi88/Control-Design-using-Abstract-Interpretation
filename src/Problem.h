//
//  Problem.h
//  Controller Synthesizer
//
//  Created by Hadi Ravanbakhsh on 6/7/13.
//  Copyright (c) 2013 Hadi Ravanbakhsh. All rights reserved.
//

#ifndef __Controller_Synthesizer__InputReader__
#define __Controller_Synthesizer__InputReader__

#include "includes.h"
#include "B_Polyhedron.h"
#include "Transformer.h"
#include "Drifter.h"
#include "../frontend/Input.h"
class Problem{
private:
    // number of modes
    int pSize;
    
    int qSize;
    
    // number of dimensions
    int nSize;
    
    // number of constraints of safe area
    int cSize;
    

    // each mode has a transformer
    vector<Transformer*> transformers;
    Drifter* drifter;
    // safe area is one polyhedron for now
    B_Polyhedron* safe;
    
public:
    int getNSize() const;
    int getPSize() const;
    int getQSize() const;
    int getCSize() const;
    B_Polyhedron& getSafe() const;
    Transformer& getTransformer(int index) const;
    Drifter& getDrifter() const;
    void read(Input* input);
    Problem(Input* input);
    double getPartitionStep(int index);
    ~Problem();
};

#endif /* defined(__Controller_Synthesizer__InputReader__) */
