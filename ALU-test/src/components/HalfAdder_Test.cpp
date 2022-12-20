#include "pch.h"
#include "components/Half_Adder.h"

namespace
{
	/*using namespace dat;

	class COMP_Half_Adder_Test : public testing::Test
	{
	public:
		void SetUp() override {}
		void TearDown() override { }

	public:
		dat::Half_Adder halfAdder;
	};

	TEST_F(COMP_Half_Adder_Test, COMP_Half_Adder_Test_0)
	{
		PIN_OFF(halfAdder, Half_Adder::A); PIN_OFF(halfAdder, Half_Adder::B);

		halfAdder.process();

		EXPECT_EQ(PIN_VAL(halfAdder, Half_Adder::SUM), OFF); EXPECT_EQ(PIN_VAL(halfAdder, Half_Adder::CARRY_OUT), OFF);
	}

	TEST_F(COMP_Half_Adder_Test, COMP_Half_Adder_Test_1)
	{
		PIN_ON(halfAdder, Half_Adder::A); PIN_OFF(halfAdder, Half_Adder::B);

		halfAdder.process();

		EXPECT_EQ(PIN_VAL(halfAdder, Half_Adder::SUM), ON); EXPECT_EQ(PIN_VAL(halfAdder, Half_Adder::CARRY_OUT), OFF);
	}

	TEST_F(COMP_Half_Adder_Test, COMP_Half_Adder_Test_2)
	{
		PIN_OFF(halfAdder, Half_Adder::A); PIN_ON(halfAdder, Half_Adder::B);

		halfAdder.process();

		EXPECT_EQ(PIN_VAL(halfAdder, Half_Adder::SUM), ON); EXPECT_EQ(PIN_VAL(halfAdder, Half_Adder::CARRY_OUT), OFF);
	}

	TEST_F(COMP_Half_Adder_Test, COMP_Half_Adder_Test_3)
	{
		PIN_ON(halfAdder, Half_Adder::A); PIN_ON(halfAdder, Half_Adder::B);

		halfAdder.process();

		EXPECT_EQ(PIN_VAL(halfAdder, Half_Adder::SUM), OFF); EXPECT_EQ(PIN_VAL(halfAdder, Half_Adder::CARRY_OUT), ON);
	}*/
}
