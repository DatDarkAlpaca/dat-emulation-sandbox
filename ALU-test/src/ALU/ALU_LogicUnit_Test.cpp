#include "pch.h"
#include "Component.h"
#include "ALU/ALU_LogicUnit.h"

class ALU_LogicUnit_Test : public testing::Test
{
public:
	void SetUp() override {}
	void TearDown() override { }

public:
	dat::ALU_LogicUnit LU;
};

TEST_F(ALU_LogicUnit_Test, ALU_LogicUnit_Test_0)
{
	using namespace dat;

	LU.pinOff(ALU_LogicUnit::A); 
	LU.pinOff(ALU_LogicUnit::B);
	LU.process();

	LU.getPin(ALU_LogicUnit::NOT_OUT);
	EXPECT_EQ(LU.getPin(ALU_LogicUnit::NOT_OUT), ON); 
	EXPECT_EQ(LU.getPin(ALU_LogicUnit::OR_OUT), OFF); 
	EXPECT_EQ(LU.getPin(ALU_LogicUnit::AND_OUT), OFF);
}

TEST_F(ALU_LogicUnit_Test, ALU_LogicUnit_Test_1)
{
	using namespace dat;

	LU.pinOff(ALU_LogicUnit::A); LU.pinOn(ALU_LogicUnit::B);
	LU.process();

	EXPECT_EQ(LU.getPin(ALU_LogicUnit::NOT_OUT), ON);
	EXPECT_EQ(LU.getPin(ALU_LogicUnit::OR_OUT), ON);
	EXPECT_EQ(LU.getPin(ALU_LogicUnit::AND_OUT), OFF);
}

TEST_F(ALU_LogicUnit_Test, ALU_LogicUnit_Test_2)
{
	using namespace dat;

	LU.pinOn(ALU_LogicUnit::A); LU.pinOff(ALU_LogicUnit::B);
	LU.process();

	EXPECT_EQ(LU.getPin(ALU_LogicUnit::NOT_OUT), OFF);
	EXPECT_EQ(LU.getPin(ALU_LogicUnit::OR_OUT), ON);
	EXPECT_EQ(LU.getPin(ALU_LogicUnit::AND_OUT), OFF);
}

TEST_F(ALU_LogicUnit_Test, ALU_LogicUnit_Test_3)
{
	using namespace dat;

	LU.pinOn(ALU_LogicUnit::A); LU.pinOn(ALU_LogicUnit::B);
	LU.process();

	EXPECT_EQ(LU.getPin(ALU_LogicUnit::NOT_OUT), OFF);
	EXPECT_EQ(LU.getPin(ALU_LogicUnit::OR_OUT), ON);
	EXPECT_EQ(LU.getPin(ALU_LogicUnit::AND_OUT), ON);
}