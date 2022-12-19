#include "pch.h"
#include "Component.h"
#include "components/Decoder2_to_4.h"

class ALU_Decoder_Test : public testing::Test
{
public:
	void SetUp() override {}
	void TearDown() override { }

public:
	dat::Decoder2_to_4 decoder;
};

TEST_F(ALU_Decoder_Test, ALU_Decoder_Test_F0)
{
	decoder.setF0(OFF);
	EXPECT_EQ(decoder.getF0(), OFF);
}

TEST_F(ALU_Decoder_Test, ALU_Decoder_Test_F1)
{
	decoder.setF1(ON);
	EXPECT_EQ(decoder.getF1(), ON);
}

TEST_F(ALU_Decoder_Test, ALU_Decoder_Test_0)
{
	// Given: F0 = OFF, F1 = OFF
	decoder.setF1(OFF); decoder.setF0(OFF);

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
	decoder.setF1(OFF); decoder.setF0(ON);

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
	decoder.setF1(ON); decoder.setF0(OFF);

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
	decoder.setF1(ON); decoder.setF0(ON);

	// For:
	decoder.process();

	// Then: Output = 1000
	EXPECT_EQ(decoder.output(3), ON);
	EXPECT_EQ(decoder.output(2), OFF);
	EXPECT_EQ(decoder.output(ON), OFF);
	EXPECT_EQ(decoder.output(OFF), OFF);
}
