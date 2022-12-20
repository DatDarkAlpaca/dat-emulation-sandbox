#include "pch.h"
#include "flip_flops/D_FlipFlop.h"

class D_FlipFlop_Test : public testing::Test
{
public:
	void SetUp() override {}
	void TearDown() override { }

public:
	dat::D_FlipFlop dFlipFlop;
};

TEST_F(D_FlipFlop_Test, D_FlipFlop_Test_Latching)
{
	using namespace dat;

	dFlipFlop.pinOn(D_FlipFlop::CLOCK);
	dFlipFlop.pinOff(D_FlipFlop::D);
	dFlipFlop.process();

	EXPECT_EQ(dFlipFlop.getPin(D_FlipFlop::Q), OFF);
	EXPECT_EQ(dFlipFlop.getPin(D_FlipFlop::Q_INV), ON);
	
	dFlipFlop.pinOff(D_FlipFlop::CLOCK);
	dFlipFlop.pinOn(D_FlipFlop::D);

	dFlipFlop.process();
	EXPECT_EQ(dFlipFlop.getPin(D_FlipFlop::Q), OFF);
	EXPECT_EQ(dFlipFlop.getPin(D_FlipFlop::Q_INV), ON);

	dFlipFlop.pinOn(D_FlipFlop::CLOCK);
	dFlipFlop.pinOn(D_FlipFlop::D);

	dFlipFlop.process();
	EXPECT_EQ(dFlipFlop.getPin(D_FlipFlop::Q), ON);
	EXPECT_EQ(dFlipFlop.getPin(D_FlipFlop::Q_INV), OFF);
}
