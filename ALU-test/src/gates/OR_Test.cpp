#include "pch.h"
#include "gates/OR_Gate.h"

class Gate_OR_Test : public testing::Test
{
public:
	void SetUp() override {}
	void TearDown() override { }

public:
	dat::OR_Gate orGate;
};

TEST_F(Gate_OR_Test, Gate_OR_Test_0)
{
	using namespace dat;

	orGate[0] = OFF; orGate[1] = OFF;
	orGate.process();

	EXPECT_EQ(orGate.getPin(OR_Gate::OUT), OFF);
}

TEST_F(Gate_OR_Test, Gate_OR_Test_1)
{
	using namespace dat;

	orGate[0] = OFF; orGate[1] = ON;
	orGate.process();

	EXPECT_EQ(orGate.getPin(OR_Gate::OUT), ON);
}

TEST_F(Gate_OR_Test, Gate_OR_Test_2)
{
	using namespace dat;

	orGate[0] = ON; orGate[1] = OFF;
	orGate.process();

	EXPECT_EQ(orGate.getPin(OR_Gate::OUT), ON);
}

TEST_F(Gate_OR_Test, Gate_OR_Test_3)
{
	using namespace dat;

	orGate[0] = ON; orGate[1] = ON;
	orGate.process();

	EXPECT_EQ(orGate.getPin(OR_Gate::OUT), ON);
}