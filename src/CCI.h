//
//  CCI.h
//  Controller Synthesizer
//
//  Created by Hadi Ravanbakhsh on 6/10/13.
//  Copyright (c) 2013 Hadi Ravanbakhsh. All rights reserved.
//

#ifndef __Controller_Synthesizer__CCI__
#define __Controller_Synthesizer__CCI__

#include "includes.h"
#include "Problem.h"
#include "T_Polyhedron.h"
#include "MaximumMap.h"
// complementary of control invarinat
class CCI {
private:
    const static int maxItr = 10000;
    // map annotations to new found annotated set
    map<Annotations, A_Set*>  newMap;
    // map annotations to old found annotated set
    map<Annotations, A_Set*>  oldMap;
    MaximumMap* maxMap;
    
    // map preannotations to new found preannotated set
    vector<map<Annotations, A_Set* > >  oldPres;
    
    set<Annotations> narrowedChoices;

    
    // variables for iteration
    bool hasChanged;
    int numOfIterations;
    int totalNumberOfPolyhedra;
    pair<map<Annotations, A_Set*> , vector<vector<pair<Annotation, Constraint> > > > cciResult;
    const Problem& problem;
    
    void iterate();
    
    void calculateNewPresAndMax();
    void updateMaxMap(Annotations ann);
    void processNewPolyhedron(A_Set* toAddPoly);
    void calculateNewPolyhera();
    void deallocate();
    
public:
    // gets ready for first iteration
    CCI(Problem& problem);
    
    // find a fixed point
    pair<map<Annotations, A_Set*> , vector<vector<pair<Annotation, Constraint> > > >& solve();
    ~CCI();
};

#endif /* defined(__Controller_Synthesizer__CCI__) */
