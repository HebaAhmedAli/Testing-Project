//
// Created by heba on 12/11/18.
//

#ifndef PROJECTTOTEST_SERVER_H
#define PROJECTTOTEST_SERVER_H

#include "queue"
#include "vector"
#include "Visitor.h"

using namespace std;
class Server {
public:
    queue<Visitor> normalPeople;   // This queue will contains normal people.
    queue<Visitor> vipPeople;      // This queue will contains vip people.
    vector<Visitor> servedPeople;

    void enterPeopleToWait(float& timer,queue<Visitor>& allPeople)
    {
        // Loop to push all people who come before this moment in their appropriate queue.
        while (!allPeople.empty()&&allPeople.front().arrivalTime <= timer)
        {
            Visitor v=allPeople.front();
            if (normalPeople.size() == 0)
            {
                v.calculatedType="normal";
                normalPeople.push(v);
            }
            else
            {
                float r = v.r;
                if (r <= 0.5)
                {
                    v.calculatedType="normal";
                    normalPeople.push(v);
                }
                else
                {
                    v.calculatedType="vip";
                    vipPeople.push(v);
                }

            }
            allPeople.pop();
        }

        if (!allPeople.empty()&&normalPeople.empty() && vipPeople.empty())
        {
            Visitor v=allPeople.front();
            v.calculatedType="normal";
            normalPeople.push(v);
            timer = v.arrivalTime;
            allPeople.pop();
        }
    }

    void startServe(float& timer,int& totalNormalWait,int& totalVipWait)
    {
        if (!vipPeople.empty())
        {
            Visitor v=vipPeople.front();
            // Serve the vip first.
            v.calculatedWaitTime = timer -  v.arrivalTime;
            totalVipWait+=v.calculatedWaitTime;
            timer = (v.arrivalTime < timer) ? timer : v.arrivalTime;
            timer += v.serviceTime;    // Add the service time to the timer.
            v.calculatedLeaveTime = timer;
            servedPeople.push_back(v);
            vipPeople.pop();
        }
        else
        {
            // Serve the normal if no vip.
            Visitor v=normalPeople.front();
            // Serve the vip first.
            v.calculatedWaitTime = timer -  v.arrivalTime;
            totalNormalWait+=v.calculatedWaitTime;
            timer = (v.arrivalTime < timer) ? timer : v.arrivalTime;
            timer += v.serviceTime;    // Add the service time to the timer.
            v.calculatedLeaveTime = timer;
            servedPeople.push_back(v);
            normalPeople.pop();
        }
    }
};


#endif //PROJECTTOTEST_SERVER_H
