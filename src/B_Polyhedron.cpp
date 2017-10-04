//
//  B_Polyhedron.cpp
//  Controller Synthesizer
//
//  Created by Hadi Ravanbakhsh on 6/7/13.
//  Copyright (c) 2013 Hadi Ravanbakhsh. All rights reserved.
//

#include "B_Polyhedron.h"
#include "Utilities.h"
#define THRESHOLD  1000000000

B_Polyhedron::B_Polyhedron(int numOfDimensions, I_Polyhedron* inPoly) {
    this->numOfDimensions = numOfDimensions;
    this->p = NNC_Polyhedron(numOfDimensions, UNIVERSE);
    int cSize = inPoly->coefs->size();
    for (int i = 0; i < cSize; i++) {
        vector<double> coefs;
        double coef;
        for (int j = 0; j < numOfDimensions; j++) {
            coefs.push_back(inPoly->coefs->at(i)->at(j));
        }
        coef = inPoly->bounds->at(i);
        coefs.push_back(coef);
        
        int factor = Utilities::getIntFactor(coefs);
        
        Linear_Expression le;
        for (int j = 0; j < numOfDimensions; j++) {
            le += round(factor * coefs[j]) * Variable(j);
        }
        Constraint c (le <= round(factor * coefs.back()));
        addConstraint(c);
    }
}

B_Polyhedron::B_Polyhedron(int numOfDimensions){
    this->numOfDimensions = numOfDimensions;
    this->p = NNC_Polyhedron(numOfDimensions, UNIVERSE);
}

B_Polyhedron::B_Polyhedron(const B_Polyhedron& bp){
    this->numOfDimensions = bp.numOfDimensions;
    this->p = NNC_Polyhedron(bp.p);
}

bool B_Polyhedron::isValid() const{
    return this->p.is_bounded();
}

bool B_Polyhedron::isEmpty() const{
    return this->p.is_empty();
}

void B_Polyhedron::addConstraint(Constraint c){
    this->p.add_constraint(c);
}

void B_Polyhedron::printPoints() const{
    if (isEmpty() || !isValid() || getNumOfDimensions() != 2) {
        return;
    }
    
    map<pair<int, int>, bool> done;
    Constraint_System cs = getConstraints();
    vector<double> points;
    int c1i = 0;
    Constraint c1 = *cs.begin();
    do {
        bool notFound = true;
        double a = c1.coefficient(Variable(0)).get_si();
        double b = c1.coefficient(Variable(1)).get_si();
        double e = -c1.inhomogeneous_term().get_si();
        int c2i = 0;
        for (Constraint_System_const_iterator it = cs.begin(); it != cs.end(); it++, c2i++) {
            Constraint c2 = (*it);
            if (c1i == c2i || done.find(make_pair(c1i, c2i)) != done.end()) {
                continue;
            }
            
            // for each constraint c1 and c2
            
            double c = c2.coefficient(Variable(0)).get_si();
            double d = c2.coefficient(Variable(1)).get_si();
            double f = -c2.inhomogeneous_term().get_si();
            
            if (a*d - b*c == 0) {
                continue;
            }
            double coeff = 1.0 / (a*d - b*c);
            
            // point is intersection of c1 and c2
            double point[2];
            point[0] = (coeff * d * e + coeff * -b * f);
            point[1] = (coeff * -c * e + coeff * a * f);
            if (Utilities::checkSatisfaction(getConstraints(), getNumOfDimensions(), point)) {
                points.push_back(point[0]);
                points.push_back(point[1]);
                
                done[make_pair(c1i, c2i)] = true;
                done[make_pair(c2i, c1i)] = true;
                c1 = (*it);
                c1i = c2i;
                notFound = false;
                break;
            }
        }
        if (notFound) {
            B_Polyhedron* temp = approximate();
            if  (!contains(*temp))
                temp->printPoints();

            delete temp;
            return;
        }
    } while (c1i != 0);
    Utilities::print("patch([");
    for (int i = 0; i < points.size() / 2; i++) {
        Utilities::print(" ");
        Utilities::print(points[2*i]);
    }
    Utilities::print("], [");
    for (int i = 0; i < points.size() / 2; i++) {
        Utilities::print(" ");
        Utilities::print(points[2*i+1]);
    }
    Utilities::print("], 'r');\n");
}

void B_Polyhedron::meet(const B_Polyhedron& pIn){
    Constraint_System cs = pIn.getConstraints();
    for (Constraint_System_const_iterator it = cs.begin(); it != cs.end(); it++) {
        Constraint c = *it;
        this->p.add_constraint(Utilities::clone(c, getNumOfDimensions()));
        p.is_empty();
    }
}

void B_Polyhedron::meetWithoutOptimization(const B_Polyhedron& pIn){
    Constraint_System cs = getConstraints();
    for (Constraint_System_const_iterator it = cs.begin(); it != cs.end(); it++) {
        Constraint c = *it;
        this->p.add_constraint(Utilities::clone(c, getNumOfDimensions()));
    }
}

B_Polyhedron* B_Polyhedron::join(const B_Polyhedron& pIn){
    B_Polyhedron* temp = pIn.clone();
    temp->p.poly_hull_assign(this->p);
    B_Polyhedron* result = temp->approximate();
    delete temp;
    return result;
}

bool B_Polyhedron::contains(const B_Polyhedron& pIn) const{
    return this->p.contains(pIn.p);
}

Constraint_System B_Polyhedron::getConstraints() const {
    return this->p.constraints();
}

int B_Polyhedron::getNumOfDimensions() const {
    return this->numOfDimensions;
}

void B_Polyhedron::setTo(const B_Polyhedron &pIn){
    this->p = pIn.clone()->p;
}

Constraint B_Polyhedron::getSeparator(const B_Polyhedron& pIn) const{
    Constraint result;
    bool isToNegateNull = true;
    Constraint_System cs = pIn.getConstraints();
    for (Constraint_System_const_iterator it = cs.begin(); it != cs.end(); it++) {
        Constraint cIn = *it;
        bool found = false;
        Constraint_System cs2 = getConstraints();
        for (Constraint_System_const_iterator it2 = cs2.begin(); it2 != cs2.end(); it2++) {
            Constraint c = *it2;
            if (cIn == c) {
                found = true;
                break;
            }
        }
        if (!found && isToNegateNull) {
            result = cIn;
            isToNegateNull = false;
        }else if (!found) {
            cout << "debug: second time" << endl;
        }
    }
    if (isToNegateNull){
        Linear_Expression le;
        for (int d = 0; d < numOfDimensions; d++) {
            le += Variable(d) * 0;
        }
        return (le > 1);
    }else{
        return Utilities::negateInequality(result, numOfDimensions);
    }
}

Constraint B_Polyhedron::maximize(Linear_Expression le, long factor) const{
    Coefficient n;
    Coefficient d;
    bool max;
    
    max = this->p.maximize(le, n, d, max);
    if (max){
        Linear_Expression result = factor * le.coefficient(Variable(0)) * Variable(0);
        for (int i = 1; i < numOfDimensions; i++) {
            result += factor * le.coefficient(Variable(i)) * Variable(i);
        }
        return result <= Coefficient_one() * (((n * factor) / d)+1);
    }else{
        cout << "can't maximize linear expression (B_Polyhedron::maximize) : ";
        Utilities::printConstraint(le <= Coefficient_zero(), numOfDimensions);
        cout << endl;
        return (0*Variable(0) <= 1);
    }
}

Coefficient B_Polyhedron::maximizeOffset(Linear_Expression le, long factor) const{
    Coefficient n;
    Coefficient d;
    bool max;
    
    max = this->p.maximize(le, n, d, max);
    if (max){
        return Coefficient_one() * (((n * factor) / d)+1);
    }else{
        cout << "can't maximize linear expression (B_Polyhedron::maximize) : ";
        Utilities::printConstraint(le <= Coefficient_zero(), numOfDimensions);
        printConstraints();
        cout << endl;
        return (-Coefficient_one());
    }
}

B_Polyhedron* B_Polyhedron::approximate() const{
    B_Polyhedron* result = new B_Polyhedron(getNumOfDimensions());
    
    // maxX and minX define a box containing the polyhedron
    vector<double> maxX;
    vector<double> minX;
    long factor = 1000000000;
    for (int d = 0; d < getNumOfDimensions(); d++) {
        Constraint c = this->maximize(Coefficient_one() * Variable(d), factor);
        double p = -c.inhomogeneous_term().get_d();
        double q = c.coefficient(Variable(d)).get_d();
        double a = p / q;
        c = this->maximize(-Coefficient_one() * Variable(d), factor);
        p = -c.inhomogeneous_term().get_d();
        q = c.coefficient(Variable(d)).get_d();
        double b = p / q;
        minX.push_back(min(a, b));
        maxX.push_back(max(a, b));
    }
    
    vector<Linear_Expression> les;
    vector<Coefficient> bs;
    vector<string> relationTypes;
    Constraint_System cs = getConstraints();
    for (Constraint_System_const_iterator it = cs.begin(); it != cs.end(); it++) {
        Constraint c = *it;
        double b = -c.inhomogeneous_term().get_d();
        Coefficient threshold = THRESHOLD;
        if (abs(b) < THRESHOLD) {
            // no need to change the constraint
            // this part can be improved by checking
            // all the coefficients instead of just b
            result->addConstraint(c);
            continue;
        }
        Coefficient denumerator = Coefficient_one();
        Coefficient temp = abs(b);
        while (temp > THRESHOLD) {
            denumerator *= 10 * Coefficient_one();
            temp = temp / (10 * Coefficient_one());
        }
        if (abs(b) > 10e+50) {
            cout << "warning: large coefficient " << abs(b) << endl;
        }
        // newB is small enough constant coefficient
        Coefficient newB = -c.inhomogeneous_term() / (denumerator);
        
        // get floor of newB
        if (newB < 0)
            newB --;
        
        les.push_back(Coefficient_zero() * Variable(0));
        for (int d = 0; d < getNumOfDimensions(); d++) {
            
            // make other coefficients small by changin newB
            Coefficient a = c.coefficient(Variable(d));
            Coefficient qd = a / denumerator;
            les.back() += qd * Coefficient_one() * Variable(d);
            Coefficient r = a - qd * denumerator;
            double rd = r.get_d() / (denumerator.get_d());
            double delta = 0;
            if (rd >= 0) {
                delta = maxX[d] * rd;
            } else {
                delta = minX[d] * rd;
            }
            newB = newB - ceil(delta);
        }
        bs.push_back(newB);
        relationTypes.push_back(Utilities::getRelationType(c));
    }
    
    for (int i = 0; i < les.size(); i++) {
        if (relationTypes[i] == EQUALITY_STR) {
            result->addConstraint(les[i] == bs[i]);
        } else if (relationTypes[i] == STRICT_STR){
            result->addConstraint(les[i] > bs[i]);
        } else {
            result->addConstraint(les[i] >= bs[i]);
        }
    }
    if (!result->contains(*this)) {
        cout << "error in approximation" << endl;
    }
    return result;
}

void B_Polyhedron::printConstraints() const{
    Constraint_System cs = getConstraints();
    for (Constraint_System_const_iterator it = cs.begin(); it != cs.end(); it++) {
        Utilities::printConstraint(*it, numOfDimensions);
        Utilities::print("\n");
    }
}

B_Polyhedron* B_Polyhedron::clone() const{
    Constraint_System cs = getConstraints();
    B_Polyhedron* res = new B_Polyhedron(getNumOfDimensions());
    
    for (Constraint_System_const_iterator it = cs.begin(); it != cs.end(); it++) {
        Constraint c = *it;
        res->addConstraint(Utilities::clone(c, getNumOfDimensions()));
    }
    
    return res;
}

Constraint B_Polyhedron::getConstraint(int index){
    return *(getConstraints().begin().operator++(index));
}

vector<Constraint> B_Polyhedron::getConstraintsVector(){
    vector<Constraint> result;
    if(p.is_empty())
        return result;
    Constraint_System cs = p.constraints();
    for (Constraint_System_const_iterator it = cs.begin(); it != cs.end(); it++) {
        result.push_back(*it);
    }
    if (result.empty()){
        cout << "debug" << endl;
    }
    return result;
}

bool B_Polyhedron::contains(vector<double> point) const{
    if (point.size() != getNumOfDimensions())
        return false;
    Constraint_System cs = getConstraints();
    for (Constraint_System_const_iterator it = cs.begin(); it != cs.end(); it++) {
        Constraint c = *it;
        double total = 0;
        for (int i = 0; i < point.size(); i++) {
            total += c.coefficient(Variable(i)).get_d() * point[i];
        }
        if (total < -c.inhomogeneous_term().get_d()) {
            return false;
        }
    }
    return true;
}

B_Polyhedron::~B_Polyhedron(){
    
}

