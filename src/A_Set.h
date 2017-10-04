//
//  A_Set.h
//  Controller Synthesizer
//
//  Created by Hadi Ravanbakhsh on 6/10/13.
//  Copyright (c) 2013 Hadi Ravanbakhsh. All rights reserved.
//

#ifndef __Controller_Synthesizer__A_Set__
#define __Controller_Synthesizer__A_Set__

#include "AbstractSet.h"

// Indicates (time)'s precondition of a (constraint) under mode (u)
class Annotation{
public:
    int u;
    int constraint;
    int time;
    bool operator<(const Annotation& a) const;
    bool operator==(const Annotation& a) const;
    Annotation();
    Annotation(const Annotation& a);
    Annotation(int u, int constraint, int time);
};

// Determines a cell (segment) uniquely
class Annotations{
public:
    const vector<Annotation> all;
public:
    bool operator<(const Annotations& a) const;

    // update one of the annotations with (a)
    Annotations getUpdated(const Annotation& a) const;
    
    // get annotation of mode (u)
    Annotation getAnnotation(int u) const;
    
    Annotations operator=(const Annotations& a) const;
    
    Annotations(vector<Annotation> annotations);
    
    Annotations(const Annotations& a);
    void print() const;
    ~Annotations();
};

// Annotated Set
class A_Set{

public:
    Annotations annotations;
    AbstractSet* cp;
    
    A_Set(AbstractSet* cp, Annotations annotations);
    ~A_Set();
};

#endif /* defined(__Controller_Synthesizer__A_Set__) */
