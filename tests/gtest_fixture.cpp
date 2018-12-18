#include "gtest/gtest.h"
#include "../src/Simulator.h"
#include "../src/Visitor.h"
#include "VisitoTest.h"
namespace {
    class SimulationTest : public ::testing::Test {
    protected:
        void SetUp() override {

            serviceTimes = {5, 4, 3, 8, 2, 5, 4, 3, 1, 6, 8, 9, 4, 3, 2, 7, 6, 6, 6, 7, 9};
        }

//        queue<Visitor> allPeople;      // This queue will contains all people.
        vector<VisitoTest> expectedPeople;
        int totalNormalWait;
        int totalVipWait;
        vector<int> serviceTimes;
        Simulator s;

    };


// TODO: Test func startSimulation in simulator.
    TEST_F(SimulationTest, testStartSimulation) {
        //  8, 2, 5,4
        // id arrivalTime serviceTime randomNo  // expectedWaitTime expectedLeaveTime expextedType
        Visitor visitor(1, 1, serviceTimes[3], 0.1);             // 0 9 normal
        VisitoTest visitoTest(1, 0, 9, "normal");
        s.allPeople.push(visitor);
        Visitor visitor2(2, 5, serviceTimes[4], 0.7);             // 9 16 normal
        VisitoTest visitoTest2(2, 9, 16, "normal");
        s.allPeople.push(visitor2);
        Visitor visitor3 = Visitor(3, 6, serviceTimes[5], 0.7);   // 3 14 vip
        VisitoTest visitoTest3(3, 3, 14, "vip");
        s.allPeople.push(visitor3);
        Visitor visitor4 = Visitor(4, 14, serviceTimes[6], 0.1);   // 2 20 normal
        VisitoTest visitoTest4(4, 2, 20, "normal");
        s.allPeople.push(visitor4);
        // Push them with the leave time ordering.
        expectedPeople.push_back(visitoTest);
        expectedPeople.push_back(visitoTest3);
        expectedPeople.push_back(visitoTest2);
        expectedPeople.push_back(visitoTest4);

        totalNormalWait =11;
        totalVipWait = 3;

        vector<Visitor> visitors = s.startSimulation();
        // TODO: Replace visitors.size() with 2 to try wrong assert
        ASSERT_EQ(visitors.size(), expectedPeople.size()) << "size mismatch" << endl;
        for (int i = 0; i < visitors.size(); i++) {
            ASSERT_EQ(visitors[i].id, expectedPeople[i].id)
                                        << "id mismatch" << endl;
            ASSERT_EQ(visitors[i].calculatedWaitTime, expectedPeople[i].expectedWaitTime)
                                        << "wait time mismatch" << endl;
            ASSERT_EQ(visitors[i].calculatedLeaveTime, expectedPeople[i].expectedLeaveTime)
                                        << "leave time mismatch" << endl;
            ASSERT_EQ(visitors[i].calculatedType, expectedPeople[i].expextedType) << "type mismatch" << endl;

        }
        ASSERT_EQ(s.totalNormalWait, totalNormalWait) << "total Normal Wait mismatch " << s.totalNormalWait << endl;

        ASSERT_EQ(s.totalVipWait, totalVipWait) << "total VIP Wait mismatch " << s.totalVipWait << endl;

        cout << "The code don't continue after found a wrong test case as using Assert.." << endl;

    }




// TODO: Test func startSimulation in simulator.
    TEST_F(SimulationTest, testStartSimulation2) {
        // id arrivalTime serviceTime randomNo  // expectedWaitTime expectedLeaveTime expextedType
        Visitor visitor(1, 1, serviceTimes[0], 0.1);             // 0 6 normal
        VisitoTest visitoTest(1, 0, 6, "normal");
        s.allPeople.push(visitor);
        Visitor visitor2(2, 5, serviceTimes[1], 0.7);             // 4 13 normal
        VisitoTest visitoTest2(2, 4, 13, "normal");
        s.allPeople.push(visitor2);
        Visitor visitor3 = Visitor(3, 6, serviceTimes[2], 0.7);   // 0 9 vip
        VisitoTest visitoTest3(3, 0, 9, "vip");
        s.allPeople.push(visitor3);
        // Push them with the leave time ordering.
        expectedPeople.push_back(visitoTest);
        expectedPeople.push_back(visitoTest3);
        expectedPeople.push_back(visitoTest2);
        totalNormalWait = 4;
        totalVipWait = 0;

        vector<Visitor> visitors = s.startSimulation();
        // TODO: Replace visitors.size() with 2 to try wrong assert
        ASSERT_EQ(visitors.size(), expectedPeople.size()) << "size mismatch" << endl;
        for (int i = 0; i < visitors.size(); i++) {
            ASSERT_EQ(visitors[i].id, expectedPeople[i].id)
                                        << "id mismatch" << endl;
            ASSERT_EQ(visitors[i].calculatedWaitTime, expectedPeople[i].expectedWaitTime)
                                        << "wait time mismatch" << endl;
            ASSERT_EQ(visitors[i].calculatedLeaveTime, expectedPeople[i].expectedLeaveTime)
                                        << "leave time mismatch" << endl;
            ASSERT_EQ(visitors[i].calculatedType, expectedPeople[i].expextedType) << "type mismatch" << endl;

        }
        ASSERT_EQ(s.totalNormalWait, totalNormalWait) << "total Normal Wait mismatch " << s.totalNormalWait << endl;

        ASSERT_EQ(s.totalVipWait, totalVipWait) << "total VIP Wait mismatch " << s.totalVipWait << endl;

        cout << "The code don't continue after found a wrong test case as using Assert.." << endl;

    }

// TODO: Test func startSimulation in simulator.
    TEST_F(SimulationTest, testStartSimulation3) {
        //  3, 1, 6, 8, 9
        // id arrivalTime serviceTime randomNo  // expectedWaitTime expectedLeaveTime expextedType
        Visitor visitor(1, 1, serviceTimes[7], 0.1);             // 0 4 normal
        VisitoTest visitoTest(1, 0, 4, "normal");
        s.allPeople.push(visitor);
        Visitor visitor2(2, 6, serviceTimes[8], 0.1);             // 0 7 normal
        VisitoTest visitoTest2(2, 0, 7, "normal");
        s.allPeople.push(visitor2);
        Visitor visitor3 = Visitor(3, 7, serviceTimes[9], 0.7);   // 0 13 normal
        VisitoTest visitoTest3(3, 0, 13, "normal");
        s.allPeople.push(visitor3);
        Visitor visitor4 = Visitor(4, 11, serviceTimes[10], 0.1);   // 2 21 normal
        VisitoTest visitoTest4(4, 2, 21, "normal");
        s.allPeople.push(visitor4);
        Visitor visitor5 = Visitor(5, 12, serviceTimes[11], 0.1);   // 9 30 normal
        VisitoTest visitoTest5(5, 9, 30, "normal");
        s.allPeople.push(visitor5);
        // Push them with the leave time ordering.
        expectedPeople.push_back(visitoTest);
        expectedPeople.push_back(visitoTest2);
        expectedPeople.push_back(visitoTest3);
        expectedPeople.push_back(visitoTest4);
        expectedPeople.push_back(visitoTest5);

        totalNormalWait =11;
        totalVipWait = 0;

        vector<Visitor> visitors = s.startSimulation();
        // TODO: Replace visitors.size() with 2 to try wrong assert
        ASSERT_EQ(visitors.size(), expectedPeople.size()) << "size mismatch" << endl;
        for (int i = 0; i < visitors.size(); i++) {
            ASSERT_EQ(visitors[i].id, expectedPeople[i].id)
                                        << "id mismatch" << endl;
            ASSERT_EQ(visitors[i].calculatedWaitTime, expectedPeople[i].expectedWaitTime)
                                        << "wait time mismatch" << endl;
            ASSERT_EQ(visitors[i].calculatedLeaveTime, expectedPeople[i].expectedLeaveTime)
                                        << "leave time mismatch" << endl;
            ASSERT_EQ(visitors[i].calculatedType, expectedPeople[i].expextedType) << "type mismatch" << endl;

        }
        ASSERT_EQ(s.totalNormalWait, totalNormalWait) << "total Normal Wait mismatch " << s.totalNormalWait << endl;

        ASSERT_EQ(s.totalVipWait, totalVipWait) << "total VIP Wait mismatch " << s.totalVipWait << endl;

        cout << "The code don't continue after found a wrong test case as using Assert.." << endl;

    }


}


