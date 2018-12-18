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
void checkAfterServing(Server server,float timer,float timerExpected,int id,int wait,int leave,string type)
{
    ASSERT_EQ(id,server.servedPeople[server.servedPeople.size()-1].id);
    ASSERT_EQ(wait,server.servedPeople[server.servedPeople.size()-1].calculatedWaitTime);
    ASSERT_EQ(leave,server.servedPeople[server.servedPeople.size()-1].calculatedLeaveTime);
    ASSERT_EQ(type,server.servedPeople[server.servedPeople.size()-1].calculatedType)
                                <<"id = "  <<server.servedPeople[server.servedPeople.size()-1].id;
    ASSERT_EQ(timerExpected,timer);

}

static bool
idCompare(const Visitor& a, const Visitor& b) {
    return a.id < b.id;
}
// Testing correct type.
TEST(SimulatorTest, correctType) {
    Simulator s;
    vector<vector<Visitor>> visitorsAllCases=s.fillAllPeopleAndSimulate("/home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/src/input.txt");
    vector<vector<VisitoTest>> visitorsAllCasesTests=readTests("/home/heba/Documents/cmp/fourth_year/Testing/Testing-Project/tests/inputTest.txt");

    for(int i=0;i<visitorsAllCases.size();i++)
    {
        sort(visitorsAllCases[i].begin(), visitorsAllCases[i].end(), idCompare);

        for(int j=0;j<visitorsAllCases[i].size();j++)
        {
            ASSERT_EQ(visitorsAllCasesTests[i][j].expextedType, visitorsAllCases[i][j].calculatedType)<< "Type mismatches Tno. "
                << i << "user id " << visitorsAllCases[i][j].id <<endl;

			ASSERT_EQ(visitorsAllCasesTests[i][j].expectedWaitTime, visitorsAllCases[i][j].calculatedWaitTime) << "wait time mismatches Tno. "
				<< i << "user id " << visitorsAllCases[i][j].id << " " << visitorsAllCasesTests[i][j].expectedWaitTime << " " << visitorsAllCases[i][j].calculatedWaitTime << endl;

			ASSERT_EQ(visitorsAllCasesTests[i][j].expectedLeaveTime, visitorsAllCases[i][j].calculatedLeaveTime) << "leave time mismatches Tno. "
				<< i << "user id " << visitorsAllCases[i][j].id<< j << " " << visitorsAllCasesTests[i][j].expectedLeaveTime << " " << visitorsAllCases[i][j].calculatedLeaveTime << endl;

        }
    }
}

// TODO: Test func enterPeopleToWait in server.
TEST(TestEnterPeopleToWait,enterCorrectly)
{
    queue<Visitor> allPeople;      // This queue will contains all people.
    // id arrivalTime serviceTime randomNo  // expectedWaitTime expectedLeaveTime expextedType
    Visitor visitor(1, 1, 5, 0.1);              // 0 6 normal
    allPeople.push(visitor);
    Visitor visitor2(2, 5, 4, 0.1);             // 7 16 normal
    allPeople.push(visitor2);
    Visitor visitor3 = Visitor(3, 6, 3, 0.7);   // 0 9 vip
    allPeople.push(visitor3);
    Visitor visitor4 = Visitor(4, 8, 3, 0.7);   // 1 12 vip
    allPeople.push(visitor4);

    float timer=6;
    allPeople.pop();  // After serving id=1.
    Server server;
    server.enterPeopleToWait(timer,allPeople);

    // TODO: Replace 1 with 2 to try wrong expect.
    EXPECT_EQ(1,server.vipPeople.size())<<"mismatch in expected vipSize at time "<<timer<<endl;
    EXPECT_EQ(1,server.normalPeople.size())<<"mismatch in expected normalSize at time "<<timer<<endl;
    EXPECT_EQ(1,allPeople.size())<<"mismatch in expected allPeopleSize at time "<<timer<<endl;
    EXPECT_EQ(3,server.vipPeople.front().id)<<"id=3 not in the vip as expected at time "<<timer<<endl;
    EXPECT_EQ(2,server.normalPeople.front().id)<<"id=2 not in the normal as expected at time "<<timer<<endl;
    EXPECT_EQ(4,allPeople.front().id)<<"id=4 not in the allPeople as expected at time "<<timer<<endl;

    timer=9;
    server.vipPeople.pop();
    server.enterPeopleToWait(timer,allPeople);


    EXPECT_EQ(1,server.vipPeople.size())<<"mismatch in expected vipSize at time "<<timer<<endl;
    EXPECT_EQ(1,server.normalPeople.size())<<"mismatch in expected normalSize at time "<<timer<<endl;
    EXPECT_EQ(0,allPeople.size())<<"mismatch in expected allPeopleSize at time "<<timer<<endl;
    EXPECT_EQ(4,server.vipPeople.front().id)<<"id=4 not in the vip as expected at time "<<timer<<endl;
    EXPECT_EQ(2,server.normalPeople.front().id)<<"id=2 not in the normal as expected at time "<<timer<<endl;

    // allPeople now is empty.

    cout<<"The code continue after found a wrong test case as using EXPECT.."<<endl;

}

// TODO: Test func enterPeopleToWait in server.
TEST(TestEnterPeopleToWait,enterCorrectly2)
{
    queue<Visitor> allPeople;      // This queue will contains all people.
    // id arrivalTime serviceTime randomNo  // expectedWaitTime expectedLeaveTime expextedType
    Visitor visitor(1, 3, 10, 0.1);              // 0 13 normal
    allPeople.push(visitor);
    Visitor visitor2(2, 9, 4, 0.7);             // 11 24 normal
    allPeople.push(visitor2);
    Visitor visitor3 = Visitor(3, 10, 3, 0.7);   // 3 16 vip
    allPeople.push(visitor3);
    Visitor visitor4 = Visitor(4, 11, 4, 0.7);   // 5 20 vip
    allPeople.push(visitor4);

    float timer=13;
    allPeople.pop();  // After serving id=1.
    Server server;
    server.enterPeopleToWait(timer,allPeople);

    // TODO: Replace 1 with 2 to try wrong expect.
    EXPECT_EQ(2,server.vipPeople.size())<<"mismatch in expected vipSize at time "<<timer<<endl;
    EXPECT_EQ(1,server.normalPeople.size())<<"mismatch in expected normalSize at time "<<timer<<endl;
    EXPECT_EQ(0,allPeople.size())<<"mismatch in expected allPeopleSize at time "<<timer<<endl;
    EXPECT_EQ(3,server.vipPeople.front().id)<<"id=3 not in the vip as expected at time "<<timer<<endl;
    EXPECT_EQ(2,server.normalPeople.front().id)<<"id=2 not in the normal as expected at time "<<timer<<endl;

    // allPeople now is empty.

    server.vipPeople.pop();

    EXPECT_EQ(4,server.vipPeople.front().id)<<"id=4 not in the vip as expected at time "<<timer<<endl;


}


// TODO: Test func startServe in server.
TEST(TestStartServe,servedCorrectly)
{
    queue<Visitor> allPeople;      // This queue will contains all people.
    // id arrivalTime serviceTime randomNo  // expectedWaitTime expectedLeaveTime expextedType
    Visitor visitor(1, 1, 5, 0.7);              // 0 6 normal
    allPeople.push(visitor);
    Visitor visitor2(2, 7, 4, 0.1);             // 0 11 normal
    allPeople.push(visitor2);
    Visitor visitor3 = Visitor(3, 8, 3, 0.1);   // 6 17 normal
    allPeople.push(visitor3);
    Visitor visitor4 = Visitor(4, 9, 3, 0.7);   // 2 14 vip
    allPeople.push(visitor4);

    Server server;
    int totalNormalWait=0;
    int totalVipWait=0;
    float timer=allPeople.front().arrivalTime;
    server.enterPeopleToWait(timer,allPeople);
    server.startServe(timer,totalNormalWait,totalVipWait);

    checkAfterServing(server,timer,6,1,0,6,"normal");


    server.enterPeopleToWait(timer,allPeople);
    ASSERT_EQ(7,timer);
    server.startServe(timer,totalNormalWait,totalVipWait);

    checkAfterServing(server,timer,11,2,0,11,"normal");


    server.enterPeopleToWait(timer,allPeople);
    ASSERT_EQ(11,timer);
    server.startServe(timer,totalNormalWait,totalVipWait);

    checkAfterServing(server,timer,14,4,2,14,"vip");

    server.enterPeopleToWait(timer,allPeople);
    ASSERT_EQ(14,timer);
    server.startServe(timer,totalNormalWait,totalVipWait);

    checkAfterServing(server,timer,17,3,6,17,"normal");

    ASSERT_EQ(6,totalNormalWait);
    ASSERT_EQ(2,totalVipWait);

}

TEST(TestStartServe,servedCorrectly_2)
{
    queue<Visitor> allPeople;      // This queue will contains all people.
    // id arrivalTime serviceTime randomNo  // expectedWaitTime expectedLeaveTime expextedType

    Visitor visitor(1, 1, 3, 0.7);   // 0  4 normal
    allPeople.push(visitor);
    Visitor visitor2(2, 3, 1, 0.7);              // 1 5 normal
    allPeople.push(visitor2);
    Visitor visitor3 = Visitor(3,  4, 1, 0.1);             // 1 6 normal
    allPeople.push(visitor3);
    Visitor visitor4 = Visitor(4, 6, 2, 0.1);   // 0 8 normal
    allPeople.push(visitor4);

    Server server;
    int totalNormalWait=0;
    int totalVipWait=0;
    float timer=allPeople.front().arrivalTime;
    server.enterPeopleToWait(timer,allPeople);
    server.startServe(timer,totalNormalWait,totalVipWait);

    // Server server,float timer,float timerExpected,int id,int wait,int leave,string type

    checkAfterServing(server,timer,4,1,0,4,"normal");


    server.enterPeopleToWait(timer,allPeople);
    server.startServe(timer,totalNormalWait,totalVipWait);
    checkAfterServing(server,timer,5,2,1,5,"normal");
    server.enterPeopleToWait(timer,allPeople);
    server.startServe(timer,totalNormalWait,totalVipWait);
    checkAfterServing(server,timer,6,3,1,6,"normal");
    server.enterPeopleToWait(timer,allPeople);
    server.startServe(timer,totalNormalWait,totalVipWait);
    checkAfterServing(server,timer,8,4,0,8,"normal");
    ASSERT_EQ(2,totalNormalWait);
    ASSERT_EQ(0,totalVipWait);

}



