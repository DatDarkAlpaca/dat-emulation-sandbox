#include "pch.h"
#include "Component.h"
#include "components/Decoder2_to_4.h"

namespace
{
	class ALU_Decoder_Test : public testing::Test
	{
	public:
		void SetUp() override {}
		void TearDown() override { }

	public:
		dat::Decoder2_to_4 decoder;
	};

	using namespace dat;

	TEST_F(ALU_Decoder_Test, ALU_Decoder_Test_F0)
	{
		PIN_OFF(decoder, Decoder2_to_4::F0);
		EXPECT_EQ(PIN_VAL(decoder, Decoder2_to_4::F0), OFF);
	}

	TEST_F(ALU_Decoder_Test, ALU_Decoder_Test_F1)
	{
		PIN_ON(decoder, Decoder2_to_4::F1);
		EXPECT_EQ(PIN_VAL(decoder, Decoder2_to_4::F1), ON);
	}

	TEST_F(ALU_Decoder_Test, ALU_Decoder_Test_0)
	{
		// Given: F0 = OFF, F1 = OFF
		PIN_OFF(decoder, Decoder2_to_4::F1); PIN_OFF(decoder, Decoder2_to_4::F0);

		// For:
		decoder.process();

		// Then: Output = 0001
		EXPECT_EQ(decoder.output(3), OFF);
		EXPECT_EQ(decoder.output(2), OFF);
		EXPECT_EQ(decoder.output(ON), OFF);
		EXPECT_EQ(decoder.output(OFF), ON);
	}

	TEST_F(ALU_Decoder_Test, ALU_Decoder_Test_1)
	{
		// Given: F0 = OFF, F1 = ON
		PIN_OFF(decoder, Decoder2_to_4::F1); PIN_ON(decoder, Decoder2_to_4::F0);

		// For:
		decoder.process();

		// Then: Output = 0010
		EXPECT_EQ(decoder.output(3), OFF);
		EXPECT_EQ(decoder.output(2), OFF);
		EXPECT_EQ(decoder.output(ON), ON);
		EXPECT_EQ(decoder.output(OFF), OFF);
	}

	TEST_F(ALU_Decoder_Test, ALU_Decoder_Test_2)
	{
		// Given: F0 = ON, F1 = OFF
		PIN_ON(decoder, Decoder2_to_4::F1); PIN_OFF(decoder, Decoder2_to_4::F0);

		// For:
		decoder.process();

		// Then: Output = 0100
		EXPECT_EQ(decoder.output(3), OFF);
		EXPECT_EQ(decoder.output(2), ON);
		EXPECT_EQ(decoder.output(ON), OFF);
		EXPECT_EQ(decoder.output(OFF), OFF);
	}

	TEST_F(ALU_Decoder_Test, ALU_Decoder_Test_3)
	{
		// Given: F0 = ON, F1 = ON
		PIN_ON(decoder, Decoder2_to_4::F1); PIN_ON(decoder, Decoder2_to_4::F0);

		// For:
		decoder.process();

		// Then: Output = 1000
		EXPECT_EQ(decoder.output(3), ON);
		EXPECT_EQ(decoder.output(2), OFF);
		EXPECT_EQ(decoder.output(ON), OFF);
		EXPECT_EQ(decoder.output(OFF), OFF);
	}

}