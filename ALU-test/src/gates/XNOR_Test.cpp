#include "pch.h"
#include "gates/XNOR_Gate.h"

class Gate_XNOR_Test : public testing::Test
{
public:
	void SetUp() override {}
	void TearDown() override { }

public:
	dat::XNOR_Gate xnorGate;
};

TEST_F(Gate_XNOR_Test, Gate_XNOR_Test_0)
{
	xnorGate[0] = 0; xnorGate[1] = 0;
	xnorGate.process();

	EXPECT_EQ(xnorGate.output(), 1);
}

TEST_F(Gate_XNOR_Test, Gate_XNOR_Test_1)
{
	xnorGate[0] = 0; xnorGate[1] = 1;
	xnorGate.process();

	EXPECT_EQ(xnorGate.output(), 0);
}

TEST_F(Gate_XNOR_Test, Gate_XNOR_Test_2)
{
	xnorGate[0] = 1; xnorGate[1] = 0;
	xnorGate.process();

	EXPECT_EQ(xnorGate.output(), 0);
}

TEST_F(Gate_XNOR_Test, Gate_XNOR_Test_3)
{
	xnorGate[0] = 1; xnorGate[1] = 1;
	xnorGate.process();

	EXPECT_EQ(xnorGate.output(), 1);
}