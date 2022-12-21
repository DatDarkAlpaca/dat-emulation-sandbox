#include "pch.h"
#include "register/Register_1bit.h"

class Register_1bit_Test : public testing::Test
{
public:
	void SetUp() override {}
	void TearDown() override { }

public:
	dat::Register_1bit register1Bit;
};

TEST_F(Register_1bit_Test, Register_1bit_Test_ENABLE)
{
	using namespace dat;

	register1Bit.pinOn(Register_1bit::ENABLE);

	EXPECT_EQ(register1Bit.getPin(Register_1bit::ENABLE), ON);
}

TEST_F(Register_1bit_Test, Register_1bit_Test_LOAD)
{
	using namespace dat;

	register1Bit.pinOn(Register_1bit::LOAD);

	EXPECT_EQ(register1Bit.getPin(Register_1bit::LOAD), ON);
}

TEST_F(Register_1bit_Test, Register_1bit_Test_CLK)
{
	using namespace dat;

	register1Bit.pinOn(Register_1bit::CLK);

	EXPECT_EQ(register1Bit.getPin(Register_1bit::CLK), ON);
}

TEST_F(Register_1bit_Test, Register_1bit_Test_0)
{
	using namespace dat;

	EXPECT_EQ(register1Bit.getPin(Register_1bit::OUT), ZERO);

	register1Bit.pinOn(Register_1bit::CLK);
	register1Bit.pinOn(Register_1bit::LOAD);
	register1Bit.pinOn(Register_1bit::D);

	register1Bit.process();

	EXPECT_EQ(register1Bit.getPin(Register_1bit::OUT), ZERO);
}

TEST_F(Register_1bit_Test, Register_1bit_Test_1)
{
	using namespace dat;

	EXPECT_EQ(register1Bit.getPin(Register_1bit::OUT), ZERO);

	register1Bit.pinOn(Register_1bit::CLK);
	register1Bit.pinOn(Register_1bit::LOAD);
	register1Bit.pinOn(Register_1bit::D);
	register1Bit.pinOff(Register_1bit::LOAD);
	register1Bit.pinOn(Register_1bit::ENABLE);

	register1Bit.process();

	EXPECT_EQ(register1Bit.getPin(Register_1bit::OUT), ON);
}

TEST_F(Register_1bit_Test, Register_1bit_Test_2)
{
	using namespace dat;

	EXPECT_EQ(register1Bit.getPin(Register_1bit::OUT), ZERO);

	register1Bit.pinOn(Register_1bit::CLK);
	register1Bit.pinOn(Register_1bit::LOAD);
	register1Bit.pinOff(Register_1bit::D);
	register1Bit.pinOn(Register_1bit::ENABLE);

	register1Bit.process();

	EXPECT_EQ(register1Bit.getPin(Register_1bit::OUT), OFF);
}
