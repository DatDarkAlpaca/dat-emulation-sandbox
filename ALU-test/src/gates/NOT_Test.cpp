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
	notGate[0] = OFF;
	notGate.process();

	EXPECT_EQ(notGate.output(), ON);
}

TEST_F(Gate_NOT_Test, Gate_NOT_Test_1)
{
	notGate[0] = ON;
	notGate.process();

	EXPECT_EQ(notGate.output(), OFF);
}