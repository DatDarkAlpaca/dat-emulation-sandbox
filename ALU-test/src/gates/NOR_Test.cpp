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
	norGate[0] = 0; norGate[1] = 0;
	norGate.process();

	EXPECT_EQ(norGate.output(), 1);
}

TEST_F(Gate_NOR_Test, Gate_NOR_Test_1)
{
	norGate[0] = 0; norGate[1] = 1;
	norGate.process();

	EXPECT_EQ(norGate.output(), 0);
}

TEST_F(Gate_NOR_Test, Gate_NOR_Test_2)
{
	norGate[0] = 1; norGate[1] = 0;
	norGate.process();

	EXPECT_EQ(norGate.output(), 0);
}

TEST_F(Gate_NOR_Test, Gate_NOR_Test_3)
{
	norGate[0] = 1; norGate[1] = 1;
	norGate.process();

	EXPECT_EQ(norGate.output(), 0);
}