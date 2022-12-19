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
	fullAdder.setA(ON);
	EXPECT_EQ(fullAdder.getA(), ON);
}

TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_B)
{
	fullAdder.setB(ON);
	EXPECT_EQ(fullAdder.getB(), ON);
}

TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_CarryIn)
{
	fullAdder.setCarryIn(ON);
	EXPECT_EQ(fullAdder.getCarryIn(), ON);
}

TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_0)
{
	fullAdder.setA(OFF); fullAdder.setB(OFF); fullAdder.setCarryIn(OFF);

	fullAdder.process();

	EXPECT_EQ(fullAdder.getSum(), OFF); EXPECT_EQ(fullAdder.getCarryOut(), OFF);
}

TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_1)
{
	fullAdder.setA(ON); fullAdder.setB(OFF); fullAdder.setCarryIn(OFF);

	fullAdder.process();

	EXPECT_EQ(fullAdder.getSum(), ON); EXPECT_EQ(fullAdder.getCarryOut(), OFF);
}

TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_2)
{
	fullAdder.setA(OFF); fullAdder.setB(ON); fullAdder.setCarryIn(OFF);

	fullAdder.process();

	EXPECT_EQ(fullAdder.getSum(), ON); EXPECT_EQ(fullAdder.getCarryOut(), OFF);
}

TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_3)
{
	fullAdder.setA(ON); fullAdder.setB(ON); fullAdder.setCarryIn(OFF);

	fullAdder.process();

	EXPECT_EQ(fullAdder.getSum(), OFF); EXPECT_EQ(fullAdder.getCarryOut(), ON);
}

TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_4)
{
	fullAdder.setA(OFF); fullAdder.setB(OFF); fullAdder.setCarryIn(ON);

	fullAdder.process();

	EXPECT_EQ(fullAdder.getSum(), ON); EXPECT_EQ(fullAdder.getCarryOut(), OFF);
}

TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_5)
{
	fullAdder.setA(ON); fullAdder.setB(OFF); fullAdder.setCarryIn(ON);

	fullAdder.process();

	EXPECT_EQ(fullAdder.getSum(), OFF); EXPECT_EQ(fullAdder.getCarryOut(), ON);
}

TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_6)
{
	fullAdder.setA(OFF); fullAdder.setB(ON); fullAdder.setCarryIn(ON);

	fullAdder.process();

	EXPECT_EQ(fullAdder.getSum(), OFF); EXPECT_EQ(fullAdder.getCarryOut(), ON);
}

TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_7)
{
	fullAdder.setA(ON); fullAdder.setB(ON); fullAdder.setCarryIn(ON);

	fullAdder.process();

	EXPECT_EQ(fullAdder.getSum(), ON); EXPECT_EQ(fullAdder.getCarryOut(), ON);
}