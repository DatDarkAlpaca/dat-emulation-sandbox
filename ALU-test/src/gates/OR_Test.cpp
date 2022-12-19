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
	orGate[0] = 0; orGate[1] = 0;
	orGate.process();

	EXPECT_EQ(orGate.output(), 0);
}

TEST_F(Gate_OR_Test, Gate_OR_Test_1)
{
	orGate[0] = 0; orGate[1] = 1;
	orGate.process();

	EXPECT_EQ(orGate.output(), 1);
}

TEST_F(Gate_OR_Test, Gate_OR_Test_2)
{
	orGate[0] = 1; orGate[1] = 0;
	orGate.process();

	EXPECT_EQ(orGate.output(), 1);
}

TEST_F(Gate_OR_Test, Gate_OR_Test_3)
{
	orGate[0] = 1; orGate[1] = 1;
	orGate.process();

	EXPECT_EQ(orGate.output(), 1);
}