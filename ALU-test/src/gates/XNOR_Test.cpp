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
	xnorGate[0] = OFF; xnorGate[1] = OFF;
	xnorGate.process();

	EXPECT_EQ(xnorGate.output(), 1);
}

TEST_F(Gate_XNOR_Test, Gate_XNOR_Test_1)
{
	xnorGate[0] = OFF; xnorGate[1] = ON;
	xnorGate.process();

	EXPECT_EQ(xnorGate.output(), 0);
}

TEST_F(Gate_XNOR_Test, Gate_XNOR_Test_2)
{
	xnorGate[0] = ON; xnorGate[1] = OFF;
	xnorGate.process();

	EXPECT_EQ(xnorGate.output(), 0);
}

TEST_F(Gate_XNOR_Test, Gate_XNOR_Test_3)
{
	xnorGate[0] = ON; xnorGate[1] = ON;
	xnorGate.process();

	EXPECT_EQ(xnorGate.output(), 1);
}