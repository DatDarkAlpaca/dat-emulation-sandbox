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
	notGate[0] = 0;
	notGate.process();

	EXPECT_EQ(notGate.output(), 1);
}

TEST_F(Gate_NOT_Test, Gate_NOT_Test_1)
{
	notGate[0] = 1;
	notGate.process();

	EXPECT_EQ(notGate.output(), 0);
}