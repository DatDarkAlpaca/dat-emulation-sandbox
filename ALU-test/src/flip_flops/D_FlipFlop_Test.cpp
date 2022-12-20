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

	SET_PIN(dFlipFlop, D_FlipFlop::CLOCK, ON);
	SET_PIN(dFlipFlop, D_FlipFlop::D, OFF);
	dFlipFlop.process();
	EXPECT_EQ(PIN_VAL(dFlipFlop, D_FlipFlop::Q), OFF); EXPECT_EQ(PIN_VAL(dFlipFlop, D_FlipFlop::Q_INV), ON);
	
	SET_PIN(dFlipFlop, D_FlipFlop::CLOCK, OFF);
	SET_PIN(dFlipFlop, D_FlipFlop::D, ON);
	dFlipFlop.process();
	EXPECT_EQ(PIN_VAL(dFlipFlop, D_FlipFlop::Q), OFF); EXPECT_EQ(PIN_VAL(dFlipFlop, D_FlipFlop::Q_INV), ON);

	SET_PIN(dFlipFlop, D_FlipFlop::CLOCK, ON);
	SET_PIN(dFlipFlop, D_FlipFlop::D, ON);
	dFlipFlop.process();
	EXPECT_EQ(PIN_VAL(dFlipFlop, D_FlipFlop::Q), ON); EXPECT_EQ(PIN_VAL(dFlipFlop, D_FlipFlop::Q_INV), OFF);
}
