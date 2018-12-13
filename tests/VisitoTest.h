//
// Created by heba on 12/12/18.
//

#ifndef PROJECTTOTEST_VISITOTEST_H
#define PROJECTTOTEST_VISITOTEST_H

#include <string>
using namespace std;

class VisitoTest {
public:
    VisitoTest(){

    }
    VisitoTest(int id,int expectedWaitTime,int expectedLeaveTime, string expextedType){
        this->id=id;
        this->expectedWaitTime=expectedWaitTime;
        this->expectedLeaveTime=expectedLeaveTime;
        this->expextedType=expextedType;
    }
    int id;
    int expectedWaitTime;
    int expectedLeaveTime;
    string expextedType;

};


#endif //PROJECTTOTEST_VISITOTEST_H
