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
	LU.setA(OFF); LU.setB(OFF);
	LU.process();

	EXPECT_EQ(LU.output(OFF), ON); EXPECT_EQ(LU.output(ON), OFF); EXPECT_EQ(LU.output(2), OFF);
}

TEST_F(ALU_LogicUnit_Test, ALU_LogicUnit_Test_1)
{
	LU.setA(OFF); LU.setB(ON);
	LU.process();

	EXPECT_EQ(LU.output(OFF), ON); EXPECT_EQ(LU.output(ON), ON); EXPECT_EQ(LU.output(2), OFF);
}

TEST_F(ALU_LogicUnit_Test, ALU_LogicUnit_Test_2)
{
	LU.setA(ON); LU.setB(OFF);
	LU.process();

	EXPECT_EQ(LU.output(OFF), OFF); EXPECT_EQ(LU.output(ON), ON); EXPECT_EQ(LU.output(2), OFF);
}

TEST_F(ALU_LogicUnit_Test, ALU_LogicUnit_Test_3)
{
	LU.setA(ON); LU.setB(ON);
	LU.process();

	EXPECT_EQ(LU.output(OFF), OFF); EXPECT_EQ(LU.output(ON), ON); EXPECT_EQ(LU.output(2), ON);
}