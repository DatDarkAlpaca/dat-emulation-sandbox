#include "pch.h"
#include "Component.h"
#include "ALU/ALU.h"

class ALU_Test : public testing::Test
{
public:
	void SetUp() override { }
	void TearDown() override { }

public:
	dat::ALU alu;
};

TEST_F(ALU_Test, ALU_Test_0)
{
	dat::ALU alu;
	alu.setF0(1); alu.setF1(1);

	alu.setNumericA(0);
	alu.setNumericB(0);
	alu.setCarryIn(0);

	alu.process();

	EXPECT_EQ((int)alu.getNumeric(), 0);
}

TEST_F(ALU_Test, ALU_Test_1)
{
	dat::ALU alu;
	alu.setF0(1); alu.setF1(1);

	alu.setNumericA(128);
	alu.setNumericB(0);
	alu.setCarryIn(0);

	alu.process();

	EXPECT_EQ((int)alu.getNumeric(), 128);
}