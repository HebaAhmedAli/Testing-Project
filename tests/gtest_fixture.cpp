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
            Visitor visitor2(2, 5, 4, 0.1);             // 4 13 normal
            VisitoTest visitoTest2(2, 4, 13, "normal");
            allPeople.push(visitor2);
            Visitor visitor3 = Visitor(3, 6, 3, 0.7);   // 0 9 vip
            VisitoTest visitoTest3(3, 0, 9, "vip");
            allPeople.push(visitor3);
            // Push them with the leave time ordering.
            expectedPeople.push_back(visitoTest);
            expectedPeople.push_back(visitoTest3);
            expectedPeople.push_back(visitoTest2);

        }

        queue<Visitor> allPeople;      // This queue will contains all people.
        vector<VisitoTest> expectedPeople;
    };


// TODO: Test func enterPeopleToWait in server.

// TODO: Test func startServe in server.


// TODO: Test func startSimulation in simulator.
    TEST_F(SimulationTest, testStartSimulation) {
        Simulator s;
        s.allPeople = this->allPeople;
        vector<Visitor> visitors = s.startSimulation();
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
    }
}



