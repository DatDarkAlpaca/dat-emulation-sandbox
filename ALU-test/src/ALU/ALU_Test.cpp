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
	alu.setF0(ON); alu.setF1(ON);

	alu.setNumericA(OFF);
	alu.setNumericB(OFF);
	alu.setCarryIn(OFF);

	alu.process();

	EXPECT_EQ((int)alu.getNumeric(), OFF);
}

TEST_F(ALU_Test, ALU_Test_1)
{
	dat::ALU alu;
	alu.setF0(ON); alu.setF1(ON);

	alu.setNumericA(128);
	alu.setNumericB(OFF);
	alu.setCarryIn(OFF);

	alu.process();

	EXPECT_EQ((int)alu.getNumeric(), 128);
}