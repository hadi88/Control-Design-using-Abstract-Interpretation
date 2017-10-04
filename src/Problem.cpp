//
//  Problem.cpp
//  Controller Synthesizer
//
//  Created by Hadi Ravanbakhsh on 6/7/13.
//  Copyright (c) 2013 Hadi Ravanbakhsh. All rights reserved.
//

#include "Problem.h"
#include "CCI.h"
#include "Utilities.h"
#include "BDD_Builder.h"
#include "T_Polyhedron.h"

void Problem::read(Input* input){
    
    this->nSize = input->numOfDimensions;
    this->qSize = input->modes->size();
    this->pSize = 0;
    for (int i = 0; i < this->qSize; i++) {
        Transformer* t = new Transformer(this->nSize, input->modes->at(i));
        if (t->isInPartition()) {
            transformers.insert(transformers.begin()+this->pSize, t);
            this->pSize++;
        }else{
            transformers.push_back(t);
        }
    }
    if (pSize == 0) {
        cerr << "at least one of the modes should be used for partitioning" << endl;
        exit(-1);
    }
    safe = new B_Polyhedron(this->nSize, input->safeRegion);
    drifter = new Drifter(nSize, input->disturbance);
    
    if (safe->isEmpty()) {
        cerr << "Safe area is empty" << endl;
        exit(-1);
    } else if (!safe->isValid()){
        cerr << "Safe area is not bounded" << endl;
        exit(-1);
    }
    B_Polyhedron* driftBox = drifter->getB();
    if (driftBox->isEmpty()){
        cerr << "Drift is empty" << endl;
        exit(-1);
    } else if (!driftBox->isValid()){
        cerr << "Drift is not bounded" << endl;
        exit(-1);
    }
    delete driftBox;
    
}
int Problem::getNSize() const{
    return this->nSize;
}

int Problem::getPSize() const{
    return this->pSize;
}

int Problem::getQSize() const{
    return this->qSize;
}

int Problem::getCSize() const{
    return this->cSize;
}

B_Polyhedron& Problem::getSafe() const{
    return *this->safe;
}

Transformer& Problem::getTransformer(int index) const{
    return *transformers[index];
}

Problem::Problem(Input* input){
    read(input);
}

Drifter& Problem::getDrifter() const{
    return *drifter;
}

Problem::~Problem(){
    for (int i = 0; i < transformers.size(); i++) {
        delete transformers[i];
    }
    delete safe;
    delete drifter;
}