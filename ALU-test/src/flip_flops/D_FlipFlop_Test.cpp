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
	dFlipFlop.setClock(true);
	dFlipFlop.setD(false);
	dFlipFlop.process();
	EXPECT_EQ(dFlipFlop.getQ(), 0); EXPECT_EQ(dFlipFlop.getQ_INV(), 1);
	
	dFlipFlop.setClock(false);
	dFlipFlop.setD(true);
	dFlipFlop.process();
	EXPECT_EQ(dFlipFlop.getQ(), 0); EXPECT_EQ(dFlipFlop.getQ_INV(), 1);

	dFlipFlop.setClock(true);
	dFlipFlop.setD(true);
	dFlipFlop.process();
	EXPECT_EQ(dFlipFlop.getQ(), 1); EXPECT_EQ(dFlipFlop.getQ_INV(), 0);
}
