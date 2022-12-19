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
	dFlipFlop.setClock(ON);
	dFlipFlop.setD(OFF);
	dFlipFlop.process();
	EXPECT_EQ(dFlipFlop.getQ(), OFF); EXPECT_EQ(dFlipFlop.getQ_INV(), ON);
	
	dFlipFlop.setClock(OFF);
	dFlipFlop.setD(ON);
	dFlipFlop.process();
	EXPECT_EQ(dFlipFlop.getQ(), OFF); EXPECT_EQ(dFlipFlop.getQ_INV(), ON);

	dFlipFlop.setClock(ON);
	dFlipFlop.setD(ON);
	dFlipFlop.process();
	EXPECT_EQ(dFlipFlop.getQ(), ON); EXPECT_EQ(dFlipFlop.getQ_INV(), OFF);
}
