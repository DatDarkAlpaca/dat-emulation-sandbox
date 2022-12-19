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
	norGate[0] = OFF; norGate[1] = OFF;
	norGate.process();

	EXPECT_EQ(norGate.output(), ON);
}

TEST_F(Gate_NOR_Test, Gate_NOR_Test_1)
{
	norGate[0] = OFF; norGate[1] = ON;
	norGate.process();

	EXPECT_EQ(norGate.output(), OFF);
}

TEST_F(Gate_NOR_Test, Gate_NOR_Test_2)
{
	norGate[0] = ON; norGate[1] = OFF;
	norGate.process();

	EXPECT_EQ(norGate.output(), OFF);
}

TEST_F(Gate_NOR_Test, Gate_NOR_Test_3)
{
	norGate[0] = ON; norGate[1] = ON;
	norGate.process();

	EXPECT_EQ(norGate.output(), OFF);
}