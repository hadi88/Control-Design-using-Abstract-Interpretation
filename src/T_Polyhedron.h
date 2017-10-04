//
//  Complex_Polyhedron.h
//  CSFPC
//
//  Created by Hadi Ravanbakhsh on 7/10/13.
//  Copyright (c) 2013 Hadi Ravanbakhsh. All rights reserved.
//

#ifndef __CSFPC__T_Polyhedron__
#define __CSFPC__T_Polyhedron__

#include "includes.h"
#include "AbstractSet.h"

class T_Polyhedron : public AbstractSet{
private:
    const static int maxWidenCounter = 5;
    int widenCounter;
    vector<int> widenCs;
    static vector<Constraint> templates;
public:
    B_Polyhedron* poly;
    static void init(int n);
    void doTemplates();
    void doJoin(const AbstractSet& pIn);
    T_Polyhedron();
    T_Polyhedron(const B_Polyhedron* bp);
    virtual void meet(const B_Polyhedron* pIn);
    virtual AbstractSet* meet(const AbstractSet& pIn) const;
    virtual bool isEmpty() const;
    virtual int getSize() const;
    virtual bool contains(const AbstractSet& pIn) const;
    virtual bool containsPoly(const B_Polyhedron* pIn) const;
    virtual void widen(const AbstractSet& pIn);
    virtual void printPoints() const;
    virtual void printConstraints() const;
    virtual AbstractSet* backward(const Transformer& tr) const;
    virtual AbstractSet* drift(const Drifter& dr) const;
    virtual AbstractSet* clone() const;
    virtual void approximate() ;
    virtual BDD_Node* getBDD() const;
    virtual bool isIn(const B_Polyhedron& pIn) const;
    virtual void meetWithoutOptimization(B_Polyhedron* pIn) const;
    virtual bool contains(vector<double> point) const;
    virtual void meetAndChange(const AbstractSet& pIn);
    virtual ~T_Polyhedron();
};

#endif /* defined(__CSFPC__T_Polyhedron__) */
