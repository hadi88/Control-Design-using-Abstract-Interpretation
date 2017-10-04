//
//  MaximumMap.h
//  Controller Synthesizer
//
//  Created by Hadi Ravanbakhsh on 6/14/13.
//  Copyright (c) 2013 Hadi Ravanbakhsh. All rights reserved.
//

#ifndef __Controller_Synthesizer__MaximumMap__
#define __Controller_Synthesizer__MaximumMap__

#include "includes.h"
#include "Problem.h"
#include "A_Set.h"

// maps annotations to maximum polyhedra of each segment
class MaximumMap{
protected:
    // map annotation to polyhedra
    map<Annotation, B_Polyhedron*> annToPoly;
    
    // maximum computed time for a mode (u)
    map<int, int> ucToMaxTime;
    
    // for each mode
    vector<multimap<Annotations, Annotations> >  neighbourPreSegments;
    vector<set<Annotations> > neighboursPreComputedSet;

    // number of modes
    int qSize;
    int pSize;
    // number of constraints
    int cSize;
    Problem& problem;
    vector<B_Polyhedron*> rests;
    void findNewSegments(int u, int c, int t);
public:
    map<Annotations, B_Polyhedron*>  annToNotDrifted;
    vector<vector<pair<Annotation, Constraint> > > constraintsList;
    MaximumMap(Problem& problem);
    virtual void addConstraint(B_Polyhedron& constraint, Constraint cons);
    set<Annotations> fullAnns;
    vector<set<Annotations> > fullPreAnns;
    // compute new maximum polyhedra for larger times
    virtual bool updateMap(Annotation ann);
    
    // get maximum polyhedra for a segment by annotations
    B_Polyhedron* getMap(Annotations ann);
    B_Polyhedron* getMap(Annotation ann);
    void updatePreNeighbours(int u, Annotations ann);
    set<Annotations> getPreNeighbours(int u, Annotations ann);
    set<Annotations> getAll();
    ~MaximumMap();
};

#endif /* defined(__Controller_Synthesizer__MaximumMap__) */
