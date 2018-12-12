//
// Created by heba on 12/11/18.
//

#ifndef PROJECTTOTEST_VISITOR_H
#define PROJECTTOTEST_VISITOR_H

#include <string>
using namespace std;
class Visitor {

public:
    int id;
    int arrivalTime;
    int serviceTime;
    float r;    // 0.5 <= normal  0.5 > vip.
    string calculatedType;   // 0 = normal 1 = vip.
    int calculatedWaitTime;
    int calculatedLeaveTime;

};


#endif //PROJECTTOTEST_VISITOR_H
