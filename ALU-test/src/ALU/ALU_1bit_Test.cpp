#include "pch.h"
#include "Component.h"
#include "ALU/ALU_1bit.h"

class ALU_1bit_Test : public testing::Test
{
public:
	void SetUp() override { }
	void TearDown() override { }

public:
	dat::ALU_1bit alu;
};

TEST_F(ALU_1bit_Test, ALU_1bit_Test_NOT_A)
{
	alu.setF0(OFF); alu.setF1(OFF);

	dat::Decoder2_to_4 decoder;
	alu.setDecoder(&decoder);

	alu.setA(OFF);
	alu.process();
	EXPECT_EQ(alu.output(), ON);

	alu.setA(ON);
	alu.process();
	EXPECT_EQ(alu.output(), OFF);
}

TEST_F(ALU_1bit_Test, ALU_1bit_Test_A_OR_B)
{
	alu.setF0(ON); alu.setF1(OFF);

	dat::Decoder2_to_4 decoder;
	alu.setDecoder(&decoder);

	alu.setA(OFF); alu.setB(OFF);
	alu.process();
	EXPECT_EQ(alu.output(), OFF);

	alu.setA(OFF); alu.setB(ON);
	alu.process();
	EXPECT_EQ(alu.output(), ON);

	alu.setA(ON); alu.setB(OFF);
	alu.process();
	EXPECT_EQ(alu.output(), ON);

	alu.setA(ON); alu.setB(ON);
	alu.process();
	EXPECT_EQ(alu.output(), ON);
}

TEST_F(ALU_1bit_Test, ALU_1bit_Test_A_AND_B)
{
	alu.setF0(OFF); alu.setF1(ON);

	dat::Decoder2_to_4 decoder;
	alu.setDecoder(&decoder);

	alu.setA(OFF); alu.setB(OFF);
	alu.process();
	EXPECT_EQ(alu.output(), OFF);

	alu.setA(OFF); alu.setB(ON);
	alu.process();
	EXPECT_EQ(alu.output(), OFF);

	alu.setA(ON); alu.setB(OFF);
	alu.process();
	EXPECT_EQ(alu.output(), OFF);

	alu.setA(ON); alu.setB(ON);
	alu.process();
	EXPECT_EQ(alu.output(), ON);
}

TEST_F(ALU_1bit_Test, ALU_1bit_Test_A_PLUS_B)
{
	alu.setF0(ON); alu.setF1(ON);

	dat::Decoder2_to_4 decoder;
	alu.setDecoder(&decoder);

	alu.setA(OFF); alu.setB(OFF); alu.setCarryIn(OFF);
	alu.process();
	EXPECT_EQ(alu.getOutput(), OFF); EXPECT_EQ(alu.getCarryOut(), OFF);

	alu.setA(ON); alu.setB(OFF); alu.setCarryIn(OFF);
	alu.process();
	EXPECT_EQ(alu.getOutput(), ON); EXPECT_EQ(alu.getCarryOut(), OFF);

	alu.setA(OFF); alu.setB(ON); alu.setCarryIn(OFF);
	alu.process();
	EXPECT_EQ(alu.getOutput(), ON); EXPECT_EQ(alu.getCarryOut(), OFF);

	alu.setA(ON); alu.setB(ON); alu.setCarryIn(OFF);
	alu.process();
	EXPECT_EQ(alu.getOutput(), OFF); EXPECT_EQ(alu.getCarryOut(), ON);

	alu.setA(OFF); alu.setB(OFF); alu.setCarryIn(ON);
	alu.process();
	EXPECT_EQ(alu.getOutput(), ON); EXPECT_EQ(alu.getCarryOut(), OFF);

	alu.setA(ON); alu.setB(OFF); alu.setCarryIn(ON);
	alu.process();
	EXPECT_EQ(alu.getOutput(), OFF); EXPECT_EQ(alu.getCarryOut(), ON);

	alu.setA(OFF); alu.setB(ON); alu.setCarryIn(ON);
	alu.process();
	EXPECT_EQ(alu.getOutput(), OFF); EXPECT_EQ(alu.getCarryOut(), ON);

	alu.setA(ON); alu.setB(ON); alu.setCarryIn(ON);
	alu.process();
	EXPECT_EQ(alu.getOutput(), ON); EXPECT_EQ(alu.getCarryOut(), ON);
}