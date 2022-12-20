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
	using namespace dat;

	nandGate[NAND_Gate::IN_0] = OFF; nandGate[NAND_Gate::IN_1] = OFF;
	nandGate.process();

	EXPECT_EQ(nandGate.getPin(NAND_Gate::OUT), ON);
}

TEST_F(Gate_NAND_Test, Gate_NAND_Test_0_1)
{
	using namespace dat;

	nandGate[NAND_Gate::IN_0] = OFF; nandGate[NAND_Gate::IN_1] = ON;
	nandGate.process();

	EXPECT_EQ(nandGate.getPin(NAND_Gate::OUT), ON);
}

TEST_F(Gate_NAND_Test, Gate_NAND_Test_0_2)
{
	using namespace dat;

	nandGate[NAND_Gate::IN_0] = ON; nandGate[NAND_Gate::IN_1] = OFF;
	nandGate.process();

	EXPECT_EQ(nandGate.getPin(NAND_Gate::OUT), ON);
}

TEST_F(Gate_NAND_Test, Gate_NAND_Test_0_3)
{
	using namespace dat;

	nandGate[NAND_Gate::IN_0] = ON; nandGate[NAND_Gate::IN_1] = ON;
	nandGate.process();

	EXPECT_EQ(nandGate.getPin(NAND_Gate::OUT), OFF);
}