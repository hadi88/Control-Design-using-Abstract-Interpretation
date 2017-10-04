//
//  Complex_Polyhedron.cpp
//  CSFPC
//
//  Created by Hadi Ravanbakhsh on 7/10/13.
//  Copyright (c) 2013 Hadi Ravanbakhsh. All rights reserved.
//

#include "T_Polyhedron.h"
#include "Utilities.h"
#include "BDD_Node.h"


vector<Constraint> T_Polyhedron::templates;

T_Polyhedron::T_Polyhedron(){
    this->poly = NULL;
    this->widenCounter = 0;
    this->widenCs.resize(templates.size());
    for (int i = 0; i < templates.size(); i++) {
        widenCs[i] = 0;
    }
}

T_Polyhedron::T_Polyhedron(const B_Polyhedron* bp){
    this->widenCounter = 0;
    this->widenCs.resize(templates.size());
    for (int i = 0; i < templates.size(); i++) {
        widenCs[i] = 0;
    }
    if (bp->isEmpty())
        return;
    this->poly = bp->clone();
}

void T_Polyhedron::init(int n){
    for (int i = 0; i < n; i++){
        Linear_Expression le = 1 * Variable(i);
        for (int j = 0; j < n; j++) {
            if (i == j) {
                continue;
            }
            le += 0 * Variable(j);
        }
        templates.push_back(le <= 0);
        templates.push_back(le >= 0);
    }
    if (n > 3)
        return;
    if (n < 2) {
        return;
    }
    // octagons
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < i; j++) {
            Linear_Expression le = 1 * Variable(i) + 1 * Variable(j);
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) {
                    continue;
                }
                le += 0 * Variable(k);
            }
            templates.push_back(le <= 0);
            templates.push_back(le >= 0);
            le = 1 * Variable(i) - 1 * Variable(j);
            for (int k = 0; k < n; k++) {
                if (k == i || k == j) {
                    continue;
                }
                le += 0 * Variable(k);
            }
            templates.push_back(le <= 0);
            templates.push_back(le >= 0);
        }
    }
    
}

bool T_Polyhedron::isEmpty() const{
    return poly->isEmpty();
}


bool T_Polyhedron::contains(const AbstractSet& pIn) const{
    if (typeid(T_Polyhedron) == typeid(pIn)) {
        T_Polyhedron& pIn2 = (T_Polyhedron&) pIn;
        return poly->contains(*(pIn2.poly));
    }
    return true;
}

bool T_Polyhedron::containsPoly(const B_Polyhedron* pIn) const{
    return poly->contains(*pIn);
}


AbstractSet* T_Polyhedron::meet(const AbstractSet& pIn) const{
    if (typeid(pIn) == typeid(T_Polyhedron)) {
        T_Polyhedron& pIn2 = (T_Polyhedron&) pIn;
        B_Polyhedron* bp = pIn2.poly->clone();
        bp->meet(*poly);
        T_Polyhedron* result = new T_Polyhedron();
        result->poly = bp;
        return result;
    }
    return new T_Polyhedron();
}

void T_Polyhedron::meet(const B_Polyhedron* pIn){
    B_Polyhedron* bp = pIn->clone();
    if (poly == NULL) {
        poly = bp;
    }else{
        poly->meet(*bp);
        delete bp;
    }
}

void T_Polyhedron::doTemplates(){
    if (poly->isEmpty()) {
        return;
    }
    long factor = 1000;
    B_Polyhedron* newP = new B_Polyhedron(poly->getNumOfDimensions());
    for (vector<Constraint>::iterator it = templates.begin(); it != templates.end(); it++) {
        Constraint c = *it;
        Linear_Expression le = c.coefficient(Variable(0)) * (Variable(0));
        for (int i = 1; i < poly->getNumOfDimensions(); i++) {
            le += c.coefficient(Variable(i)) * (Variable(i));
        }
        newP->addConstraint(poly->maximize(le, factor));
    }
    delete poly;
    poly = newP;
}

bool isSensitive(Constraint c, int numOfDimensions){
    bool isSensitive = (c.inhomogeneous_term() != Coefficient_zero() && (c.inhomogeneous_term() < Coefficient_one()*100 && c.inhomogeneous_term() > -Coefficient_one()*100));
    for (int i = 0; i < numOfDimensions; i++) {
        Coefficient coeff = c.coefficient(Variable(i));
        if(coeff != Coefficient_zero() &&
           coeff < Coefficient_one() * 100 && coeff < -Coefficient_one() * 100){
            isSensitive = true;
        }
    }
    return isSensitive;
}

bool isLarge(Constraint c){
    return c.inhomogeneous_term() > 10000000000 || c.inhomogeneous_term() < -10000000000;
}

void T_Polyhedron::approximate(){
    B_Polyhedron* bp = poly->approximate();
    delete poly;
    poly = bp;
}

AbstractSet* T_Polyhedron::drift(const Drifter& dr) const{
    T_Polyhedron* result = new T_Polyhedron();
    result->poly = (dr.drift(*poly));
    return result;
}

AbstractSet* T_Polyhedron::backward(const Transformer& tr) const{
    T_Polyhedron* result = new T_Polyhedron();
    result->poly = (tr.backward(*poly));
    return result;
}

AbstractSet* T_Polyhedron::clone() const{
    T_Polyhedron* res = new T_Polyhedron();
    res->poly = poly->clone();
    res->widenCounter = widenCounter;
    res->widenCs = vector<int>(widenCs);
    return res;
}


int T_Polyhedron::getSize() const{
    return 1;
}

void T_Polyhedron::doJoin(const AbstractSet& pIn){
    if (typeid(T_Polyhedron) == typeid(pIn)) {
        T_Polyhedron& pIn2 = (T_Polyhedron&) pIn;
        if (pIn2.isEmpty())
            return;
        long factor = 1000;
        B_Polyhedron* newP = new B_Polyhedron(poly->getNumOfDimensions());
        int cIndex = 0;
        for (vector<Constraint>::iterator it = templates.begin(); it != templates.end(); it++) {
            Constraint c = *it;
            if (widenCs[cIndex] < maxWidenCounter) {
                Linear_Expression le;
                for (int i = 0; i < poly->getNumOfDimensions(); i++) {
                    le += c.coefficient(Variable(i)) * (Variable(i));
                }
                Coefficient max = poly->maximizeOffset(-le, factor);
                Coefficient temp = pIn2.poly->maximizeOffset(-le, factor);
                if (temp > max) {
                    max = temp;
                    widenCs[cIndex]++;
                }
                newP->addConstraint(factor * le > -max);
            }
            cIndex++;
        }
        delete poly;
        poly = newP;
    }
}

void T_Polyhedron::widen(const AbstractSet& pIn){
    if (typeid(T_Polyhedron) == typeid(pIn)) {
        T_Polyhedron& pIn2 = (T_Polyhedron&) pIn;
        if (pIn2.isEmpty())
            return;
        if (isEmpty()) {
            this->poly = pIn2.poly->clone();
        }
        doJoin(pIn2);
    }
}


void T_Polyhedron::printPoints() const{
    poly->printPoints();
}

void T_Polyhedron::printConstraints() const{
    poly->printConstraints();
}

BDD_Node* T_Polyhedron::getBDD() const {
    return new BDD_Node(poly->getConstraintsVector(), &BDD_Node::ACCEPTED_LEAF, &BDD_Node::REJECTED_LEAF);
}

bool T_Polyhedron::isIn(const B_Polyhedron &pIn) const{
    return pIn.contains(*poly);
}

void T_Polyhedron::meetWithoutOptimization(B_Polyhedron* pIn) const{
    this->poly->meetWithoutOptimization(*pIn);
}

bool T_Polyhedron::contains(vector<double> point) const{
    return poly->contains(point);
}
void T_Polyhedron::meetAndChange(const AbstractSet& pIn){
    if (typeid(pIn) == typeid(T_Polyhedron)) {
        T_Polyhedron& pIn2 = (T_Polyhedron&) pIn;
        poly->meet(*(pIn2.poly));
    }
}

T_Polyhedron::~T_Polyhedron(){
    delete poly;
}
