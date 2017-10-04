//
//  Drifter.h
//  Controller Synthesizer
//
//  Created by Hadi Ravanbakhsh on 2/19/14.
//  Copyright (c) 2014 Hadi Ravanbakhsh. All rights reserved.
//

#ifndef __Controller_Synthesizer__Drifter__
#define __Controller_Synthesizer__Drifter__

#include <iostream>
#include "includes.h"
#include "B_Polyhedron.h"
#include "../frontend/I_Polyhedron.h"
class Drifter{
private:
    int size;
    B_Polyhedron b;
public:
    Drifter(int size, I_Polyhedron* disturbance);
    B_Polyhedron* drift(const B_Polyhedron& pIn) const;
    Constraint drift(const Constraint& c) const;
    B_Polyhedron* getB();
    ~Drifter();
};
#endif /* defined(__Controller_Synthesizer__Drifter__) */
