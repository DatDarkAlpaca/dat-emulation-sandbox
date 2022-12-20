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
	using namespace dat;

	xorGate[0] = OFF; xorGate[1] = OFF;
	xorGate.process();

	EXPECT_EQ(xorGate.getPin(XOR_Gate::OUT), OFF);
}

TEST_F(Gate_XOR_Test, Gate_XOR_Test_1)
{
	using namespace dat;

	xorGate[0] = OFF; xorGate[1] = ON;
	xorGate.process();

	EXPECT_EQ(xorGate.getPin(XOR_Gate::OUT), ON);
}

TEST_F(Gate_XOR_Test, Gate_XOR_Test_2)
{
	using namespace dat;

	xorGate[0] = ON; xorGate[1] = OFF;
	xorGate.process();

	EXPECT_EQ(xorGate.getPin(XOR_Gate::OUT), ON);
}

TEST_F(Gate_XOR_Test, Gate_XOR_Test_3)
{
	using namespace dat;

	xorGate[0] = ON; xorGate[1] = ON;
	xorGate.process();

	EXPECT_EQ(xorGate.getPin(XOR_Gate::OUT), OFF);
}