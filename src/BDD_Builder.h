//
//  BDD_Builder.h
//  Controller Synthesizer
//
//  Created by Hadi Ravanbakhsh on 1/30/14.
//  Copyright (c) 2014 Hadi Ravanbakhsh. All rights reserved.
//

#ifndef __Controller_Synthesizer__BDD_Builder__
#define __Controller_Synthesizer__BDD_Builder__

#include "includes.h"
#include "A_Set.h"
#include "BDD_Node.h"
#include "Problem.h"

class BDD_Builder{
private:
    map<Annotations, A_Set*>& finalMap;
    vector<vector<pair<Annotation, Constraint> > >& partitionConstraints;
    const Problem& problem;
    // returns best u and best time for decision
    int totalPoly;
    vector<int> maxTimes;
    set<Annotation> restrictions;
    bool isAcceptable(Annotations ann);
    vector<Constraint> createPolyhedron();
public:
    BDD_Builder(const Problem& problem, map<Annotations, A_Set*>& finalMap, vector<vector<pair<Annotation, Constraint> > >& partitionConstraints);
    BDD_Node* build();
};
#endif /* defined(__Controller_Synthesizer__BDD_Builder__) */
