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
	fullAdder.setA(OFF); fullAdder.setB(OFF);

	fullAdder.process();

	EXPECT_EQ(fullAdder.getSum(), OFF); EXPECT_EQ(fullAdder.getCarryOut(), OFF);
}

TEST_F(COMP_Half_Adder_Test, COMP_Half_Adder_Test_1)
{
	fullAdder.setA(ON); fullAdder.setB(OFF);

	fullAdder.process();
	
	EXPECT_EQ(fullAdder.getSum(), ON); EXPECT_EQ(fullAdder.getCarryOut(), OFF);
}

TEST_F(COMP_Half_Adder_Test, COMP_Half_Adder_Test_2)
{
	fullAdder.setA(OFF); fullAdder.setB(ON);

	fullAdder.process();

	EXPECT_EQ(fullAdder.getSum(), ON); EXPECT_EQ(fullAdder.getCarryOut(), OFF);
}

TEST_F(COMP_Half_Adder_Test, COMP_Half_Adder_Test_3)
{
	fullAdder.setA(ON); fullAdder.setB(ON);

	fullAdder.process();

	EXPECT_EQ(fullAdder.getSum(), OFF); EXPECT_EQ(fullAdder.getCarryOut(), ON);
}