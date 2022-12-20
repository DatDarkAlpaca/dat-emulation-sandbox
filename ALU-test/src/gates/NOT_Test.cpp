#include "pch.h"
#include "gates/NOT_Gate.h"

class Gate_NOT_Test : public testing::Test
{
public:
	void SetUp() override {}
	void TearDown() override { }

public:
	dat::NOT_Gate notGate;
};

TEST_F(Gate_NOT_Test, Gate_NOT_Test_0)
{
	using namespace dat;

	notGate[0] = OFF;
	notGate.process();

	EXPECT_EQ(notGate.getPin(NOT_Gate::OUT), ON);
}

TEST_F(Gate_NOT_Test, Gate_NOT_Test_1)
{
	using namespace dat;

	notGate[0] = ON;
	notGate.process();

	EXPECT_EQ(notGate.getPin(NOT_Gate::OUT), OFF);
}