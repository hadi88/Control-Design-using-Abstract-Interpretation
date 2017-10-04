//
//  A_Set.cpp
//  Controller Synthesizer
//
//  Created by Hadi Ravanbakhsh on 6/10/13.
//  Copyright (c) 2013 Hadi Ravanbakhsh. All rights reserved.
//

#include "A_Set.h"

// Annotation
Annotation::Annotation(){
    this->u = -1;
    this->constraint = -1;
    this->time = -1;
}
Annotation::Annotation(int u, int constraint, int time){
    this->u = u;
    this->constraint = constraint;
    this->time = time;
}

Annotation::Annotation(const Annotation& a){
    this->u = a.u;
    this->constraint = a.constraint;
    this->time = a.time;
}

bool Annotation::operator<(const Annotation& a) const{
    if (this->u < a.u) {
        return true;
    } else if (this->u > a.u){
        return false;
    } else {
        if (this->constraint < a.constraint) {
            return true;
        } else if (this->constraint > a.constraint){
            return false;
        } else {
            return this->time < a.time;
        }
    }
}

bool Annotation::operator==(const Annotation& a) const{
    return (this->u == a.u && this->time == a.time && this->constraint == a.constraint);
}

//Annotatins
Annotations::Annotations(vector<Annotation> annotations): all(annotations){
}

Annotations Annotations::getUpdated(const Annotation& a) const{
    vector<Annotation> newAll = all;
    newAll[a.u] = a;
    return Annotations(newAll);
}

Annotation Annotations::getAnnotation(int u) const{
    return all[u];
}


Annotations Annotations::operator=(const Annotations& a) const{
    return Annotations(a.all);
}


bool Annotations::operator<(const Annotations& a) const{
    for (int i = 0; i < this->all.size(); i++) {
        if (this->all[i] < a.all[i])
            return true;
        else if (a.all[i] < this->all[i])
            return false;
    }
    return false;
}

void Annotations::print() const{
    for (int u = 0; u < all.size(); u++) {
        cout << "u = " << u << " : ";
        cout << "c = " << all[u].constraint << " : ";
        cout << "t = " << all[u].time << endl;
    }
    cout << endl;
}

Annotations::Annotations(const Annotations& a): all(a.all){
}


Annotations::~Annotations(){
    
}

// A_Set
A_Set::A_Set(AbstractSet* cp, Annotations annotations): annotations(annotations){
    this->cp = cp;
}


A_Set::~A_Set(){
    delete cp;
}