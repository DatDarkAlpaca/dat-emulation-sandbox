#include "pch.h"
#include "gates/NAND_Gate.h"

class Gate_NAND_Test : public testing::Test
{
public:
	void SetUp() override {}
	void TearDown() override { }

public:
	dat::NAND_Gate nandGate;
};

TEST_F(Gate_NAND_Test, Gate_NAND_Test_0_0)
{
	nandGate[0] = OFF; nandGate[1] = OFF;
	nandGate.process();

	EXPECT_EQ(nandGate.output(), ON);
}

TEST_F(Gate_NAND_Test, Gate_NAND_Test_0_1)
{
	nandGate[0] = OFF; nandGate[1] = ON;
	nandGate.process();

	EXPECT_EQ(nandGate.output(), ON);
}

TEST_F(Gate_NAND_Test, Gate_NAND_Test_0_2)
{
	nandGate[0] = ON; nandGate[1] = OFF;
	nandGate.process();

	EXPECT_EQ(nandGate.output(), ON);
}

TEST_F(Gate_NAND_Test, Gate_NAND_Test_0_3)
{
	nandGate[0] = ON; nandGate[1] = ON;
	nandGate.process();

	EXPECT_EQ(nandGate.output(), OFF);
}