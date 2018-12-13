//
// Created by heba on 12/11/18.
//

#ifndef PROJECTTOTEST_VISITOR_H
#define PROJECTTOTEST_VISITOR_H

#include <string>
using namespace std;
class Visitor {

public:
    Visitor(){

    }
    Visitor(int id,int arrivalTime,int serviceTime,float r)
    {
        this->id=id;
        this->arrivalTime=arrivalTime;
        this->serviceTime=serviceTime;
        this->r=r;
    }
    int id;
    int arrivalTime;
    int serviceTime;
    float r;    // 0.5 <= normal  0.5 > vip.
    string calculatedType;   // 0 = normal 1 = vip.
    int calculatedWaitTime;
    int calculatedLeaveTime;

};


#endif //PROJECTTOTEST_VISITOR_H
