#include "gtest/gtest.h"
#include "../src/Simulator.h"
#include "../src/Visitor.h"
#include "VisitoTest.h"
namespace {
    class SimulationTest : public ::testing::Test {
    protected:
        void SetUp() override {
            // id arrivalTime serviceTime randomNo  // expectedWaitTime expectedLeaveTime expextedType
            Visitor visitor(1, 1, 5, 0.1);             // 0 6 normal
            VisitoTest visitoTest(1, 0, 6, "normal");
            allPeople.push(visitor);
            Visitor visitor2(2, 5, 4, 0.7);             // 4 13 normal
            VisitoTest visitoTest2(2, 4, 13, "normal");
            allPeople.push(visitor2);
            Visitor visitor3 = Visitor(3, 6, 3, 0.7);   // 0 9 vip
            VisitoTest visitoTest3(3, 0, 9, "vip");
            allPeople.push(visitor3);
            // Push them with the leave time ordering.
            expectedPeople.push_back(visitoTest);
            expectedPeople.push_back(visitoTest3);
            expectedPeople.push_back(visitoTest2);
			totalNormalWait = 4;
			totalVipWait = 0;
        }

        queue<Visitor> allPeople;      // This queue will contains all people.
        vector<VisitoTest> expectedPeople;
        int totalNormalWait;
        int totalVipWait;
    };


// TODO: Test func startSimulation in simulator.
    TEST_F(SimulationTest, testStartSimulation) {
        Simulator s;
        s.allPeople = this->allPeople;
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

        cout<<"The code don't continue after found a wrong test case as using Assert.."<<endl;

    }
}



