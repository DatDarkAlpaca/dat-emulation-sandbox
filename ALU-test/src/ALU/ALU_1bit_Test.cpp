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
	using namespace dat;

	alu.pinOff(ALU_1bit::F0);
	alu.pinOff(ALU_1bit::F1);

	Decoder2_to_4 decoder;
	alu.setDecoder(&decoder);

	alu.pinOff(ALU_1bit::A);
	alu.process();
	EXPECT_EQ(alu.getPin(ALU_1bit::OUT), ON);

	alu.pinOn(ALU_1bit::A);
	alu.process();
	EXPECT_EQ(alu.getPin(ALU_1bit::OUT), OFF);
}

TEST_F(ALU_1bit_Test, ALU_1bit_Test_A_OR_B)
{
	using namespace dat;

	alu.pinOn(ALU_1bit::F0);
	alu.pinOff(ALU_1bit::F1);

	Decoder2_to_4 decoder;
	alu.setDecoder(&decoder);

	alu.pinOff(ALU_1bit::A); 
	alu.pinOff(ALU_1bit::B);
	alu.process();
	EXPECT_EQ(alu.getPin(ALU_1bit::OUT), OFF);

	alu.pinOff(ALU_1bit::A); 
	alu.pinOn(ALU_1bit::B);
	alu.process();
	EXPECT_EQ(alu.getPin(ALU_1bit::OUT), ON);

	alu.pinOn(ALU_1bit::A);
	alu.pinOff(ALU_1bit::B);
	alu.process();
	EXPECT_EQ(alu.getPin(ALU_1bit::OUT), ON);

	alu.pinOn(ALU_1bit::A);
	alu.pinOn(ALU_1bit::B);
	alu.process();
	EXPECT_EQ(alu.getPin(ALU_1bit::OUT), ON);
}

TEST_F(ALU_1bit_Test, ALU_1bit_Test_A_AND_B)
{
	using namespace dat;

	alu.pinOff(ALU_1bit::F0);
	alu.pinOn(ALU_1bit::F1);

	dat::Decoder2_to_4 decoder;
	alu.setDecoder(&decoder);

	alu.pinOff(ALU_1bit::A); alu.pinOff(ALU_1bit::B);
	alu.process();
	EXPECT_EQ(alu.getPin(ALU_1bit::OUT), OFF);

	alu.pinOff(ALU_1bit::A); alu.pinOn(ALU_1bit::B);
	alu.process();
	EXPECT_EQ(alu.getPin(ALU_1bit::OUT), OFF);

	alu.pinOn(ALU_1bit::A);alu.pinOff(ALU_1bit::B);
	alu.process();
	EXPECT_EQ(alu.getPin(ALU_1bit::OUT), OFF);

	alu.pinOn(ALU_1bit::A);alu.pinOn(ALU_1bit::B);
	alu.process();
	EXPECT_EQ(alu.getPin(ALU_1bit::OUT), ON);
}

TEST_F(ALU_1bit_Test, ALU_1bit_Test_A_PLUS_B)
{
	using namespace dat;

	alu.pinOn(ALU_1bit::F0);
	alu.pinOn(ALU_1bit::F1);

	dat::Decoder2_to_4 decoder;
	alu.setDecoder(&decoder);

	alu.pinOff(ALU_1bit::A); alu.pinOff(ALU_1bit::B); alu.pinOff(ALU_1bit::CARRY_IN);
	alu.process();
	EXPECT_EQ(alu.getPin(ALU_1bit::OUT), OFF); EXPECT_EQ(alu.getPin(ALU_1bit::CARRY_OUT), OFF);

	alu.pinOn(ALU_1bit::A);alu.pinOff(ALU_1bit::B); alu.pinOff(ALU_1bit::CARRY_IN);
	alu.process();
	EXPECT_EQ(alu.getPin(ALU_1bit::OUT), ON); EXPECT_EQ(alu.getPin(ALU_1bit::CARRY_OUT), OFF);

	alu.pinOff(ALU_1bit::A); alu.pinOn(ALU_1bit::B); alu.pinOff(ALU_1bit::CARRY_IN);
	alu.process();
	EXPECT_EQ(alu.getPin(ALU_1bit::OUT), ON); EXPECT_EQ(alu.getPin(ALU_1bit::CARRY_OUT), OFF);

	alu.pinOn(ALU_1bit::A);alu.pinOn(ALU_1bit::B); alu.pinOff(ALU_1bit::CARRY_IN);
	alu.process();
	EXPECT_EQ(alu.getPin(ALU_1bit::OUT), OFF); EXPECT_EQ(alu.getPin(ALU_1bit::CARRY_OUT), ON);

	alu.pinOff(ALU_1bit::A); alu.pinOff(ALU_1bit::B); alu.pinOn(ALU_1bit::CARRY_IN);
	alu.process();
	EXPECT_EQ(alu.getPin(ALU_1bit::OUT), ON); EXPECT_EQ(alu.getPin(ALU_1bit::CARRY_OUT), OFF);

	alu.pinOn(ALU_1bit::A);alu.pinOff(ALU_1bit::B); alu.pinOn(ALU_1bit::CARRY_IN);
	alu.process();
	EXPECT_EQ(alu.getPin(ALU_1bit::OUT), OFF); EXPECT_EQ(alu.getPin(ALU_1bit::CARRY_OUT), ON);

	alu.pinOff(ALU_1bit::A); alu.pinOn(ALU_1bit::B); alu.pinOn(ALU_1bit::CARRY_IN);
	alu.process();
	EXPECT_EQ(alu.getPin(ALU_1bit::OUT), OFF); EXPECT_EQ(alu.getPin(ALU_1bit::CARRY_OUT), ON);

	alu.pinOn(ALU_1bit::A);alu.pinOn(ALU_1bit::B); alu.pinOn(ALU_1bit::CARRY_IN);
	alu.process();
	EXPECT_EQ(alu.getPin(ALU_1bit::OUT), ON); EXPECT_EQ(alu.getPin(ALU_1bit::CARRY_OUT), ON);
}