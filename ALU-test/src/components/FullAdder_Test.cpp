#include "pch.h"
#include "components/Full_Adder.h"

class COMP_Full_Adder_Test : public testing::Test
{
public:
	void SetUp() override {}
	void TearDown() override { }

public:
	dat::Full_Adder fullAdder;
};

TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_A)
{
	fullAdder.setA(1);
	EXPECT_EQ(fullAdder.getA(), 1);
}

TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_B)
{
	fullAdder.setB(1);
	EXPECT_EQ(fullAdder.getB(), 1);
}

TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_CarryIn)
{
	fullAdder.setCarryIn(1);
	EXPECT_EQ(fullAdder.getCarryIn(), 1);
}

TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_0)
{
	// Given: A = 0, B = 0, Carry = 0
	fullAdder.setA(0); fullAdder.setB(0); fullAdder.setCarryIn(0);

	// When:
	fullAdder.process();

	// Then: Sum = 0, Carry = 0
	EXPECT_EQ(fullAdder.getSum(), 0); EXPECT_EQ(fullAdder.getCarryOut(), 0);
}

TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_1)
{
	// Given: A = 1, B = 0, Carry = 0
	fullAdder.setA(1); fullAdder.setB(0); fullAdder.setCarryIn(0);

	// When:
	fullAdder.process();

	// Then: Sum = 1, Carry = 0
	EXPECT_EQ(fullAdder.getSum(), 1); EXPECT_EQ(fullAdder.getCarryOut(), 0);
}

TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_2)
{
	// Given: A = 0, B = 1, Carry = 0
	fullAdder.setA(0); fullAdder.setB(1); fullAdder.setCarryIn(0);

	// When:
	fullAdder.process();

	// Then: Sum = 1, Carry = 0
	EXPECT_EQ(fullAdder.getSum(), 1); EXPECT_EQ(fullAdder.getCarryOut(), 0);
}

TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_3)
{
	// Given: A = 1, B = 1, Carry = 0
	fullAdder.setA(1); fullAdder.setB(1); fullAdder.setCarryIn(0);

	// When:
	fullAdder.process();

	// Then: Sum = 1, Carry = 0
	EXPECT_EQ(fullAdder.getSum(), 0); EXPECT_EQ(fullAdder.getCarryOut(), 1);
}

TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_4)
{
	// Given: A = 0, B = 0, Carry = 1
	fullAdder.setA(0); fullAdder.setB(0); fullAdder.setCarryIn(1);

	// When:
	fullAdder.process();

	// Then: Sum = 1, Carry = 0
	EXPECT_EQ(fullAdder.getSum(), 1); EXPECT_EQ(fullAdder.getCarryOut(), 0);
}

TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_5)
{
	// Given: A = 1, B = 0, Carry = 1
	fullAdder.setA(1); fullAdder.setB(0); fullAdder.setCarryIn(1);

	// When:
	fullAdder.process();

	// Then: Sum = 1, Carry = 0
	EXPECT_EQ(fullAdder.getSum(), 0); EXPECT_EQ(fullAdder.getCarryOut(), 1);
}

TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_6)
{
	// Given: A = 0, B = 1, Carry = 0
	fullAdder.setA(0); fullAdder.setB(1); fullAdder.setCarryIn(1);

	// When:
	fullAdder.process();

	// Then: Sum = 1, Carry = 0
	EXPECT_EQ(fullAdder.getSum(), 0); EXPECT_EQ(fullAdder.getCarryOut(), 1);
}

TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_7)
{
	// Given: A = 1, B = 1, Carry = 1
	fullAdder.setA(1); fullAdder.setB(1); fullAdder.setCarryIn(1);

	// When:
	fullAdder.process();

	// Then: Sum = 1, Carry = 1
	EXPECT_EQ(fullAdder.getSum(), 1); EXPECT_EQ(fullAdder.getCarryOut(), 1);
}