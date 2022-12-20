#include "pch.h"
#include "gates/NOR_Gate.h"

class Gate_NOR_Test : public testing::Test
{
public:
	void SetUp() override {}
	void TearDown() override { }

public:
	dat::NOR_Gate norGate;
};

TEST_F(Gate_NOR_Test, Gate_NOR_Test_0)
{
	using namespace dat;

	norGate[0] = OFF; norGate[1] = OFF;
	norGate.process();

	EXPECT_EQ(norGate.getPin(NOR_Gate::OUT), ON);
}

TEST_F(Gate_NOR_Test, Gate_NOR_Test_1)
{
	using namespace dat;

	norGate[0] = OFF; norGate[1] = ON;
	norGate.process();

	EXPECT_EQ(norGate.getPin(NOR_Gate::OUT), OFF);
}

TEST_F(Gate_NOR_Test, Gate_NOR_Test_2)
{
	using namespace dat;

	norGate[0] = ON; norGate[1] = OFF;
	norGate.process();

	EXPECT_EQ(norGate.getPin(NOR_Gate::OUT), OFF);
}

TEST_F(Gate_NOR_Test, Gate_NOR_Test_3)
{
	using namespace dat;

	norGate[0] = ON; norGate[1] = ON;
	norGate.process();

	EXPECT_EQ(norGate.getPin(NOR_Gate::OUT), OFF);
}