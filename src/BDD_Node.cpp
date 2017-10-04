//
//  BDD_Node.cpp
//  Controller Synthesizer
//
//  Created by Hadi Ravanbakhsh on 1/30/14.
//  Copyright (c) 2014 Hadi Ravanbakhsh. All rights reserved.
//

#include "BDD_Node.h"
#include "Utilities.h"
int BDD_Node::numOfNodes = 0;

BDD_Node::BDD_Node(Constraint c, BDD_Node* tChild, BDD_Node* fChild){
    this->c.push_back(c);
    this->tChild = tChild;
    this->fChild = fChild;
}

BDD_Node::BDD_Node(vector<Constraint> c, BDD_Node* tChild, BDD_Node* fChild){
    this->c = c;
    this->tChild = tChild;
    this->fChild = fChild;
}

BDD_Node BDD_Node::ACCEPTED_LEAF(Coefficient_zero()*Variable(0) <= 1, NULL, NULL);
BDD_Node BDD_Node::REJECTED_LEAF(Coefficient_zero()*Variable(0) >= 1, NULL, NULL);

int BDD_Node::getHeight(){
    if (this == &ACCEPTED_LEAF || this == &REJECTED_LEAF) {
        return 0;
    }
    return max(tChild->getHeight(), fChild->getHeight()) + 1;
}

int BDD_Node::getNumOfOperations(){
    if (this == &ACCEPTED_LEAF || this == &REJECTED_LEAF) {
        return 0;
    }
    return (int) c.size() + max(tChild->getNumOfOperations(), fChild->getNumOfOperations());
}

void BDD_Node::generateCode(string indent, int numOfDimensions){
    if (this == &ACCEPTED_LEAF) {
        Utilities::print(indent.c_str());
        Utilities::print("result = 1;\n");
        return;
    }
    if (this == &REJECTED_LEAF) {
        Utilities::print(indent.c_str());
        Utilities::print("result = 0;\n");
        return;
    }
    
    Utilities::print(indent.c_str());
    Utilities::print("if ( ");
    Utilities::printConstraint(c[0], numOfDimensions);
    for (int i = 1; i < c.size(); i++) {
        Utilities::print(" && ");
        Utilities::printConstraint(c[i], numOfDimensions);
    }
    Utilities::print(" ) \n");
    tChild->generateCode(indent+"\t", numOfDimensions);
    Utilities::print(indent.c_str());
    Utilities::print("else\n");
    fChild->generateCode(indent+"\t", numOfDimensions);
    Utilities::print(indent.c_str());
    Utilities::print("end\n");
}


BDD_Node::~BDD_Node(){
    if (tChild != NULL && tChild != &ACCEPTED_LEAF && tChild != &REJECTED_LEAF) {
        delete tChild;
    }
    if (fChild != NULL && fChild != &ACCEPTED_LEAF && fChild != &REJECTED_LEAF) {
        delete fChild;
    }
}