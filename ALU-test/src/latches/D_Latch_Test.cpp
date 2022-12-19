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
	dLatch.setD(0); dLatch.setEnable(0);
	dLatch.process();
	EXPECT_EQ(dLatch.getQ(), 1); EXPECT_EQ(dLatch.getQ_INV(), 0);

	dLatch.setD(1); dLatch.setEnable(0);
	dLatch.process();
	EXPECT_EQ(dLatch.getQ(), 1); EXPECT_EQ(dLatch.getQ_INV(), 0);

	dLatch.setD(1); dLatch.setEnable(1);
	dLatch.process();
	EXPECT_EQ(dLatch.getQ(), 1); EXPECT_EQ(dLatch.getQ_INV(), 0);

	dLatch.setD(0); dLatch.setEnable(1);
	dLatch.process();
	EXPECT_EQ(dLatch.getQ(), 0); EXPECT_EQ(dLatch.getQ_INV(), 1);

	dLatch.setD(1); dLatch.setEnable(1);
	dLatch.process();
	EXPECT_EQ(dLatch.getQ(), 1); EXPECT_EQ(dLatch.getQ_INV(), 0);
}
