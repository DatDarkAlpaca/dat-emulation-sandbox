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
	andGate[0] = 0; andGate[1] = 0;
	andGate.process();

	EXPECT_EQ(andGate.output(), 0);
}

TEST_F(Gate_AND_Test, Gate_AND_Test_1)
{
	andGate[0] = 0; andGate[1] = 1;
	andGate.process();

	EXPECT_EQ(andGate.output(), 0);
}

TEST_F(Gate_AND_Test, Gate_AND_Test_2)
{
	andGate[0] = 1; andGate[1] = 0;
	andGate.process();

	EXPECT_EQ(andGate.output(), 0);
}

TEST_F(Gate_AND_Test, Gate_AND_Test_3)
{
	andGate[0] = 1; andGate[1] = 1;
	andGate.process();

	EXPECT_EQ(andGate.output(), 1);
}