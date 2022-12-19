#include "pch.h"
#include "components/Half_Adder.h"

class COMP_Half_Adder_Test : public testing::Test
{
public:
	void SetUp() override {}
	void TearDown() override { }

public:
	dat::Half_Adder fullAdder;
};

TEST_F(COMP_Half_Adder_Test, COMP_Half_Adder_Test_0)
{
	// Given: A = 0, B = 0
	fullAdder.setA(0); fullAdder.setB(0);

	// When:
	fullAdder.process();

	// Then: Sum = 0, Carry = 0
	EXPECT_EQ(fullAdder.getSum(), 0); EXPECT_EQ(fullAdder.getCarryOut(), 0);
}

TEST_F(COMP_Half_Adder_Test, COMP_Half_Adder_Test_1)
{
	// Given: A = 1, B = 0
	fullAdder.setA(1); fullAdder.setB(0);

	// When:
	fullAdder.process();

	// Then: Sum = 1, Carry = 0
	EXPECT_EQ(fullAdder.getSum(), 1); EXPECT_EQ(fullAdder.getCarryOut(), 0);
}

TEST_F(COMP_Half_Adder_Test, COMP_Half_Adder_Test_2)
{
	// Given: A = 0, B = 1
	fullAdder.setA(0); fullAdder.setB(1);

	// When:
	fullAdder.process();

	// Then: Sum = 1, Carry = 0
	EXPECT_EQ(fullAdder.getSum(), 1); EXPECT_EQ(fullAdder.getCarryOut(), 0);
}

TEST_F(COMP_Half_Adder_Test, COMP_Half_Adder_Test_3)
{
	// Given: A = 1, B = 1
	fullAdder.setA(1); fullAdder.setB(1);

	// When:
	fullAdder.process();

	// Then: Sum = 1, Carry = 0
	EXPECT_EQ(fullAdder.getSum(), 0); EXPECT_EQ(fullAdder.getCarryOut(), 1);
}