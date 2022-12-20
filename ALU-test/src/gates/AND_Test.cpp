#include "pch.h"
#include "gates/AND_Gate.h"

class Gate_AND_Test : public testing::Test
{
public:
	void SetUp() override {}
	void TearDown() override { }

public:
	dat::AND_Gate andGate;
};

TEST_F(Gate_AND_Test, Gate_AND_Test_0)
{
	using namespace dat;

	andGate.pinOff(AND_Gate::IN_0);
	andGate.pinOff(AND_Gate::IN_1);
	andGate.process();

	EXPECT_EQ(andGate.getPin(dat::AND_Gate::OUT), OFF);
}

TEST_F(Gate_AND_Test, Gate_AND_Test_1)
{
	using namespace dat;

	andGate.pinOff(AND_Gate::IN_0);
	andGate.pinOn(AND_Gate::IN_1);
	andGate.process();

	EXPECT_EQ(andGate.getPin(AND_Gate::OUT), OFF);
}

TEST_F(Gate_AND_Test, Gate_AND_Test_2)
{
	using namespace dat;

	andGate.pinOn(AND_Gate::IN_0);
	andGate.pinOff(AND_Gate::IN_1);
	andGate.process();

	EXPECT_EQ(andGate.getPin(AND_Gate::OUT), OFF);
}

TEST_F(Gate_AND_Test, Gate_AND_Test_3)
{
	using namespace dat;

	andGate.pinOn(AND_Gate::IN_0);
	andGate.pinOn(AND_Gate::IN_1);
	andGate.process();

	EXPECT_EQ(andGate.getPin(AND_Gate::OUT), ON);
}