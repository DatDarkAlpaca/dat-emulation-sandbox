#include "pch.h"
#include "latches/SR_Latch.h"

class Latch_SR_Latch_Test : public testing::Test
{
public:
	void SetUp() override {}
	void TearDown() override { }

public:
	dat::SR_Latch srLatch;
};

TEST_F(Latch_SR_Latch_Test, Latch_SR_Latch_Test_Latching)
{
	srLatch.setR(0); srLatch.setS(0);
	srLatch.process();
	EXPECT_EQ(srLatch.getQ(), 1); EXPECT_EQ(srLatch.getQ_INV(), 0);

	srLatch.setR(1); srLatch.setS(0);
	srLatch.process();
	EXPECT_EQ(srLatch.getQ(), 0); EXPECT_EQ(srLatch.getQ_INV(), 1);

	srLatch.setR(0); srLatch.setS(0);
	srLatch.process();
	EXPECT_EQ(srLatch.getQ(), 0); EXPECT_EQ(srLatch.getQ_INV(), 1);

	srLatch.setR(0); srLatch.setS(1);
	srLatch.process();
	EXPECT_EQ(srLatch.getQ(), 1); EXPECT_EQ(srLatch.getQ_INV(), 0);
}
