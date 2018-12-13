#include "gtest/gtest.h"
#include "../src/Simulator.h"
#include "../src/Visitor.h"
#include "VisitoTest.h"

vector<vector<VisitoTest>> readTests(string filePath)
{
    vector<vector<VisitoTest>> visitorsAllCases;
    ifstream f;
    f.open(filePath,ios::in);
    vector<VisitoTest> visitors;
    string line;
    while(getline(f,line)) {
        if(line[0]=='#')   // A comment line.
            continue;
        else if(line[0]=='X')  // The end of one test case so start simulation.
        {
            visitorsAllCases.push_back(visitors);
            visitors.clear();
            continue;
        }

        stringstream lineStream(line);
        VisitoTest v;
        lineStream >> v.id >> v.expectedWaitTime >> v.expectedLeaveTime >> v.expextedType ;
        visitors.push_back(v);
    }
    return visitorsAllCases;
}

static bool
idCompare(const Visitor& a, const Visitor& b) {
    return a.id < b.id;
}
// Testing correct type.
TEST(SimulatorTest, correctType) {
    Simulator s;
    vector<vector<Visitor>> visitorsAllCases=s.fillAllPeopleAndSimulate("/home/heba/Documents/cmp/fourth_year/Testing/ProjectToTest/src/input.txt");
    vector<vector<VisitoTest>> visitorsAllCasesTests=readTests("/home/heba/Documents/cmp/fourth_year/Testing/ProjectToTest/tests/inputTest.txt");
    for(int i=0;i<visitorsAllCases.size();i++)
    {
        sort(visitorsAllCases[i].begin(), visitorsAllCases[i].end(), idCompare);

        for(int j=0;j<visitorsAllCases[i].size();j++)
        {
            ASSERT_EQ(visitorsAllCasesTests[i][j].expextedType, visitorsAllCases[i][j].calculatedType)<<visitorsAllCasesTests[i][j].id
                               <<visitorsAllCases[i][j].id;

			ASSERT_EQ(visitorsAllCasesTests[i][j].expectedWaitTime, visitorsAllCases[i][j].calculatedWaitTime) << "wait time mismatches Tno. "
				<< i << "user " << j << " " << visitorsAllCasesTests[i][j].expectedWaitTime << " " << visitorsAllCases[i][j].calculatedWaitTime << endl;

			ASSERT_EQ(visitorsAllCasesTests[i][j].calculatedLeaveTime, visitorsAllCases[i][j].calculatedLeaveTime) << "leave time mismatches Tno. "
				<< i << "user " << j << " " << visitorsAllCasesTests[i][j].calculatedLeaveTime << " " << visitorsAllCases[i][j].calculatedLeaveTime << endl;


		

        }
    }
}

// TODO: Test func enterPeopleToWait in server.

// TODO: Test func startServe in server.
