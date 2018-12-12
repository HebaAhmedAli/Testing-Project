//
// Created by heba on 12/11/18.
//

#ifndef PROJECTTOTEST_SIMULATOR_H
#define PROJECTTOTEST_SIMULATOR_H

#include <string>
#include <queue>
#include <fstream>
#include <sstream>
#include "Server.h"
#include "Visitor.h"


using namespace std;

class Simulator {

public:
    Server server;
    queue<Visitor> allPeople;      // This queue will contains all people.
    int totalNormalWait=0;
    int totalVipWait=0;

    vector<vector<Visitor>> fillAllPeopleAndSimulate(string filePath)
    {
        vector<vector<Visitor>> visitorsAllCases;
        ifstream f;
        f.open(filePath,ios::in);

        // For testing perpose.
        ofstream out;
        out.open("/home/heba/Documents/cmp/fourth_year/Testing/ProjectToTest/src/output.txt", ios::out);
        //////////////////////.

        string line;
        while(getline(f,line)) {
            if(line[0]=='#')   // A comment line.
                continue;
            else if(line[0]=='X')  // The end of one test case so start simulation.
            {
                totalNormalWait=0;
                totalVipWait=0;
                server.servedPeople.clear();
                visitorsAllCases.push_back(startSimulation());
                printStatistics(server.servedPeople,out);
                continue;
            }

            stringstream lineStream(line);
            Visitor v;
            lineStream >> v.id >> v.arrivalTime >> v.serviceTime >> v.r ;
            allPeople.push(v);
        }

        out.close();

        return visitorsAllCases;
    }

    vector<Visitor> startSimulation()
    {
        float timer = allPeople.front().arrivalTime;
        server.enterPeopleToWait(timer,allPeople);
        while (!allPeople.empty())
        {
            server.startServe(timer,allPeople,totalNormalWait,totalVipWait);
        }

        while (!server.normalPeople.empty() || !server.vipPeople.empty())
        {
            server.startServe(timer,allPeople,totalNormalWait,totalVipWait);
        }
        return server.servedPeople;
    }

    void printStatistics(vector<Visitor> servedPeople,ofstream& out)
    {

        for (int i=0;i<servedPeople.size();i++)
        {
            out<<servedPeople[i].id<<" "<<servedPeople[i].calculatedType<<" "<<servedPeople[i].calculatedWaitTime<<
                 " " << servedPeople[i].calculatedLeaveTime<<endl;
        }
        out<<"totalNormalWait = "<<totalNormalWait<<" ,totalVipWait = "<<totalVipWait<<endl;
    }

};


#endif //PROJECTTOTEST_SIMULATOR_H
