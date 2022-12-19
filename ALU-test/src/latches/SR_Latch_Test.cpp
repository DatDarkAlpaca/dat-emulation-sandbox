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
	srLatch.setR(OFF); srLatch.setS(OFF);
	srLatch.process();
	EXPECT_EQ(srLatch.getQ(), ON); EXPECT_EQ(srLatch.getQ_INV(), OFF);

	srLatch.setR(ON); srLatch.setS(OFF);
	srLatch.process();
	EXPECT_EQ(srLatch.getQ(), OFF); EXPECT_EQ(srLatch.getQ_INV(), ON);

	srLatch.setR(OFF); srLatch.setS(OFF);
	srLatch.process();
	EXPECT_EQ(srLatch.getQ(), OFF); EXPECT_EQ(srLatch.getQ_INV(), ON);

	srLatch.setR(OFF); srLatch.setS(ON);
	srLatch.process();
	EXPECT_EQ(srLatch.getQ(), ON); EXPECT_EQ(srLatch.getQ_INV(), OFF);
}
