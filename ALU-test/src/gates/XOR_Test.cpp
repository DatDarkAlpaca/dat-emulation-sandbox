#include "pch.h"
#include "gates/XOR_Gate.h"

class Gate_XOR_Test : public testing::Test
{
public:
	void SetUp() override {}
	void TearDown() override { }

public:
	dat::XOR_Gate xorGate;
};

TEST_F(Gate_XOR_Test, Gate_XOR_Test_0)
{
	xorGate[0] = 0; xorGate[1] = 0;
	xorGate.process();

	EXPECT_EQ(xorGate.output(), 0);
}

TEST_F(Gate_XOR_Test, Gate_XOR_Test_1)
{
	xorGate[0] = 0; xorGate[1] = 1;
	xorGate.process();

	EXPECT_EQ(xorGate.output(), 1);
}

TEST_F(Gate_XOR_Test, Gate_XOR_Test_2)
{
	xorGate[0] = 1; xorGate[1] = 0;
	xorGate.process();

	EXPECT_EQ(xorGate.output(), 1);
}

TEST_F(Gate_XOR_Test, Gate_XOR_Test_3)
{
	xorGate[0] = 1; xorGate[1] = 1;
	xorGate.process();

	EXPECT_EQ(xorGate.output(), 0);
}