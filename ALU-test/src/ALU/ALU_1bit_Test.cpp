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
	alu.setF0(0); alu.setF1(0);

	dat::Decoder2_to_4 decoder;
	alu.setDecoder(&decoder);

	alu.setA(0);
	alu.process();
	EXPECT_EQ(alu.output(), 1);

	alu.setA(1);
	alu.process();
	EXPECT_EQ(alu.output(), 0);
}

TEST_F(ALU_1bit_Test, ALU_1bit_Test_A_OR_B)
{
	alu.setF0(1); alu.setF1(0);

	dat::Decoder2_to_4 decoder;
	alu.setDecoder(&decoder);

	alu.setA(0); alu.setB(0);
	alu.process();
	EXPECT_EQ(alu.output(), 0);

	alu.setA(0); alu.setB(1);
	alu.process();
	EXPECT_EQ(alu.output(), 1);

	alu.setA(1); alu.setB(0);
	alu.process();
	EXPECT_EQ(alu.output(), 1);

	alu.setA(1); alu.setB(1);
	alu.process();
	EXPECT_EQ(alu.output(), 1);
}

TEST_F(ALU_1bit_Test, ALU_1bit_Test_A_AND_B)
{
	alu.setF0(0); alu.setF1(1);

	dat::Decoder2_to_4 decoder;
	alu.setDecoder(&decoder);

	alu.setA(0); alu.setB(0);
	alu.process();
	EXPECT_EQ(alu.output(), 0);

	alu.setA(0); alu.setB(1);
	alu.process();
	EXPECT_EQ(alu.output(), 0);

	alu.setA(1); alu.setB(0);
	alu.process();
	EXPECT_EQ(alu.output(), 0);

	alu.setA(1); alu.setB(1);
	alu.process();
	EXPECT_EQ(alu.output(), 1);
}

TEST_F(ALU_1bit_Test, ALU_1bit_Test_A_PLUS_B)
{
	alu.setF0(1); alu.setF1(1);

	dat::Decoder2_to_4 decoder;
	alu.setDecoder(&decoder);

	alu.setA(0); alu.setB(0); alu.setCarryIn(0);
	alu.process();
	EXPECT_EQ(alu.getOutput(), 0); EXPECT_EQ(alu.getCarryOut(), 0);

	alu.setA(1); alu.setB(0); alu.setCarryIn(0);
	alu.process();
	EXPECT_EQ(alu.getOutput(), 1); EXPECT_EQ(alu.getCarryOut(), 0);

	alu.setA(0); alu.setB(1); alu.setCarryIn(0);
	alu.process();
	EXPECT_EQ(alu.getOutput(), 1); EXPECT_EQ(alu.getCarryOut(), 0);

	alu.setA(1); alu.setB(1); alu.setCarryIn(0);
	alu.process();
	EXPECT_EQ(alu.getOutput(), 0); EXPECT_EQ(alu.getCarryOut(), 1);

	alu.setA(0); alu.setB(0); alu.setCarryIn(1);
	alu.process();
	EXPECT_EQ(alu.getOutput(), 1); EXPECT_EQ(alu.getCarryOut(), 0);

	alu.setA(1); alu.setB(0); alu.setCarryIn(1);
	alu.process();
	EXPECT_EQ(alu.getOutput(), 0); EXPECT_EQ(alu.getCarryOut(), 1);

	alu.setA(0); alu.setB(1); alu.setCarryIn(1);
	alu.process();
	EXPECT_EQ(alu.getOutput(), 0); EXPECT_EQ(alu.getCarryOut(), 1);

	alu.setA(1); alu.setB(1); alu.setCarryIn(1);
	alu.process();
	EXPECT_EQ(alu.getOutput(), 1); EXPECT_EQ(alu.getCarryOut(), 1);
}