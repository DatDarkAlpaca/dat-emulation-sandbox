#include "pch.h"
#include "latches/D_Latch.h"

class Latch_D_Latch_Test : public testing::Test
{
public:
	void SetUp() override {}
	void TearDown() override { }

public:
	dat::D_Latch dLatch;
};

TEST_F(Latch_D_Latch_Test, Latch_D_Latch_Test_Latching)
{
	dLatch.setD(OFF); dLatch.setEnable(OFF);
	dLatch.process();
	EXPECT_EQ(dLatch.getQ(), ON); EXPECT_EQ(dLatch.getQ_INV(), OFF);

	dLatch.setD(ON); dLatch.setEnable(OFF);
	dLatch.process();
	EXPECT_EQ(dLatch.getQ(), ON); EXPECT_EQ(dLatch.getQ_INV(), OFF);

	dLatch.setD(ON); dLatch.setEnable(ON);
	dLatch.process();
	EXPECT_EQ(dLatch.getQ(), ON); EXPECT_EQ(dLatch.getQ_INV(), OFF);

	dLatch.setD(OFF); dLatch.setEnable(ON);
	dLatch.process();
	EXPECT_EQ(dLatch.getQ(), OFF); EXPECT_EQ(dLatch.getQ_INV(), ON);

	dLatch.setD(ON); dLatch.setEnable(ON);
	dLatch.process();
	EXPECT_EQ(dLatch.getQ(), ON); EXPECT_EQ(dLatch.getQ_INV(), OFF);
}
