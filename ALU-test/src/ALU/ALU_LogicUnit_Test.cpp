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
	LU.setA(0); LU.setB(0);
	LU.process();

	EXPECT_EQ(LU.output(0), 1); EXPECT_EQ(LU.output(1), 0); EXPECT_EQ(LU.output(2), 0);
}

TEST_F(ALU_LogicUnit_Test, ALU_LogicUnit_Test_1)
{
	LU.setA(0); LU.setB(1);
	LU.process();

	EXPECT_EQ(LU.output(0), 1); EXPECT_EQ(LU.output(1), 1); EXPECT_EQ(LU.output(2), 0);
}

TEST_F(ALU_LogicUnit_Test, ALU_LogicUnit_Test_2)
{
	LU.setA(1); LU.setB(0);
	LU.process();

	EXPECT_EQ(LU.output(0), 0); EXPECT_EQ(LU.output(1), 1); EXPECT_EQ(LU.output(2), 0);
}

TEST_F(ALU_LogicUnit_Test, ALU_LogicUnit_Test_3)
{
	LU.setA(1); LU.setB(1);
	LU.process();

	EXPECT_EQ(LU.output(0), 0); EXPECT_EQ(LU.output(1), 1); EXPECT_EQ(LU.output(2), 1);
}