//
//  BDD_Node.h
//  Controller Synthesizer
//
//  Created by Hadi Ravanbakhsh on 1/30/14.
//  Copyright (c) 2014 Hadi Ravanbakhsh. All rights reserved.
//

#ifndef __Controller_Synthesizer__BDD_Node__
#define __Controller_Synthesizer__BDD_Node__

#include "includes.h"

class BDD_Node{
    
private:
    vector<Constraint> c;
    BDD_Node* tChild;
    BDD_Node* fChild;
    static int numOfNodes;
    BDD_Node(Constraint c, BDD_Node* tChild, BDD_Node* fChild);
public:
    
    static BDD_Node ACCEPTED_LEAF;
    static BDD_Node REJECTED_LEAF;
    
    BDD_Node(vector<Constraint> c, BDD_Node* tChild, BDD_Node* fChild);
    void generateCode(string indent, int numOfDimensions);
    int getHeight();
    int getNumOfOperations();
    ~BDD_Node();
};
#endif /* defined(__Controller_Synthesizer__BDD_Node__) */
