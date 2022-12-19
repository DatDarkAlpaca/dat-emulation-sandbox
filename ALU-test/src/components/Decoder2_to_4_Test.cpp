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
	decoder.setF0(0);
	EXPECT_EQ(decoder.getF0(), 0);
}

TEST_F(ALU_Decoder_Test, ALU_Decoder_Test_F1)
{
	decoder.setF1(1);
	EXPECT_EQ(decoder.getF1(), 1);
}

TEST_F(ALU_Decoder_Test, ALU_Decoder_Test_0)
{
	// Given: F0 = 0, F1 = 0
	decoder.setF1(0); decoder.setF0(0);

	// For:
	decoder.process();

	// Then: Output = 0001
	EXPECT_EQ(decoder.output(3), 0);
	EXPECT_EQ(decoder.output(2), 0);
	EXPECT_EQ(decoder.output(1), 0);
	EXPECT_EQ(decoder.output(0), 1);
}

TEST_F(ALU_Decoder_Test, ALU_Decoder_Test_1)
{
	// Given: F0 = 0, F1 = 1
	decoder.setF1(0); decoder.setF0(1);

	// For:
	decoder.process();

	// Then: Output = 0010
	EXPECT_EQ(decoder.output(3), 0);
	EXPECT_EQ(decoder.output(2), 0);
	EXPECT_EQ(decoder.output(1), 1);
	EXPECT_EQ(decoder.output(0), 0);
}

TEST_F(ALU_Decoder_Test, ALU_Decoder_Test_2)
{
	// Given: F0 = 1, F1 = 0
	decoder.setF1(1); decoder.setF0(0);

	// For:
	decoder.process();

	// Then: Output = 0100
	EXPECT_EQ(decoder.output(3), 0);
	EXPECT_EQ(decoder.output(2), 1);
	EXPECT_EQ(decoder.output(1), 0);
	EXPECT_EQ(decoder.output(0), 0);
}

TEST_F(ALU_Decoder_Test, ALU_Decoder_Test_3)
{
	// Given: F0 = 1, F1 = 1
	decoder.setF1(1); decoder.setF0(1);

	// For:
	decoder.process();

	// Then: Output = 1000
	EXPECT_EQ(decoder.output(3), 1);
	EXPECT_EQ(decoder.output(2), 0);
	EXPECT_EQ(decoder.output(1), 0);
	EXPECT_EQ(decoder.output(0), 0);
}
