#include "pch.h"
#include "components/Full_Adder.h"

namespace
{
	/*using namespace dat;

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
		PIN_ON(fullAdder, Full_Adder::A);
		EXPECT_EQ(PIN_VAL(fullAdder, Full_Adder::A), ON);
	}

	TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_B)
	{
		PIN_ON(fullAdder, Full_Adder::B);
		EXPECT_EQ(PIN_VAL(fullAdder, Full_Adder::B), ON);
	}

	TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_CarryIn)
	{
		PIN_ON(fullAdder, Full_Adder::CARRY_IN);
		EXPECT_EQ(PIN_VAL(fullAdder, Full_Adder::CARRY_IN), ON);
	}

	TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_0)
	{
		PIN_OFF(fullAdder, Full_Adder::A); PIN_OFF(fullAdder, Full_Adder::B); PIN_OFF(fullAdder, Full_Adder::CARRY_IN);

		fullAdder.process();

		EXPECT_EQ(PIN_VAL(fullAdder, Full_Adder::SUM), OFF); EXPECT_EQ(PIN_VAL(fullAdder, Full_Adder::CARRY_OUT), OFF);
	}

	TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_1)
	{
		PIN_ON(fullAdder, Full_Adder::A); PIN_OFF(fullAdder, Full_Adder::B); PIN_OFF(fullAdder, Full_Adder::CARRY_IN);

		fullAdder.process();

		EXPECT_EQ(PIN_VAL(fullAdder, Full_Adder::SUM), ON); EXPECT_EQ(PIN_VAL(fullAdder, Full_Adder::CARRY_OUT), OFF);
	}

	TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_2)
	{
		PIN_OFF(fullAdder, Full_Adder::A); PIN_ON(fullAdder, Full_Adder::B); PIN_OFF(fullAdder, Full_Adder::CARRY_IN);

		fullAdder.process();

		EXPECT_EQ(PIN_VAL(fullAdder, Full_Adder::SUM), ON); EXPECT_EQ(PIN_VAL(fullAdder, Full_Adder::CARRY_OUT), OFF);
	}

	TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_3)
	{
		PIN_ON(fullAdder, Full_Adder::A); PIN_ON(fullAdder, Full_Adder::B); PIN_OFF(fullAdder, Full_Adder::CARRY_IN);

		fullAdder.process();

		EXPECT_EQ(PIN_VAL(fullAdder, Full_Adder::SUM), OFF); EXPECT_EQ(PIN_VAL(fullAdder, Full_Adder::CARRY_OUT), ON);
	}

	TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_4)
	{
		PIN_OFF(fullAdder, Full_Adder::A); PIN_OFF(fullAdder, Full_Adder::B); PIN_ON(fullAdder, Full_Adder::CARRY_IN);

		fullAdder.process();

		EXPECT_EQ(PIN_VAL(fullAdder, Full_Adder::SUM), ON); EXPECT_EQ(PIN_VAL(fullAdder, Full_Adder::CARRY_OUT), OFF);
	}

	TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_5)
	{
		PIN_ON(fullAdder, Full_Adder::A); PIN_OFF(fullAdder, Full_Adder::B); PIN_ON(fullAdder, Full_Adder::CARRY_IN);

		fullAdder.process();

		EXPECT_EQ(PIN_VAL(fullAdder, Full_Adder::SUM), OFF); EXPECT_EQ(PIN_VAL(fullAdder, Full_Adder::CARRY_OUT), ON);
	}

	TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_6)
	{
		PIN_OFF(fullAdder, Full_Adder::A); PIN_ON(fullAdder, Full_Adder::B); PIN_ON(fullAdder, Full_Adder::CARRY_IN);

		fullAdder.process();

		EXPECT_EQ(PIN_VAL(fullAdder, Full_Adder::SUM), OFF); EXPECT_EQ(PIN_VAL(fullAdder, Full_Adder::CARRY_OUT), ON);
	}

	TEST_F(COMP_Full_Adder_Test, COMP_Full_Adder_Test_7)
	{

		PIN_ON(fullAdder, Full_Adder::A); PIN_ON(fullAdder, Full_Adder::B); PIN_ON(fullAdder, Full_Adder::CARRY_IN);

		fullAdder.process();

		EXPECT_EQ(PIN_VAL(fullAdder, Full_Adder::SUM), ON); EXPECT_EQ(PIN_VAL(fullAdder, Full_Adder::CARRY_OUT), ON);
	}*/
}
