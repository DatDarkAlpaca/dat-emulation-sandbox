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
	using namespace dat;

	srLatch.pinOff(SR_Latch::R);
	srLatch.pinOff(SR_Latch::S);
	srLatch.process();
	EXPECT_EQ(srLatch.getPin(SR_Latch::Q), ON);
	EXPECT_EQ(srLatch.getPin(SR_Latch::Q_INV), OFF);

	srLatch.pinOn(SR_Latch::R);
	srLatch.pinOff(SR_Latch::S);
	srLatch.process();
	EXPECT_EQ(srLatch.getPin(SR_Latch::Q), OFF);
	EXPECT_EQ(srLatch.getPin(SR_Latch::Q_INV), ON);

	srLatch.pinOff(SR_Latch::R);
	srLatch.pinOff(SR_Latch::S);
	srLatch.process();
	EXPECT_EQ(srLatch.getPin(SR_Latch::Q), OFF);
	EXPECT_EQ(srLatch.getPin(SR_Latch::Q_INV), ON);

	srLatch.pinOff(SR_Latch::R);
	srLatch.pinOn(SR_Latch::S);
	srLatch.process();
	EXPECT_EQ(srLatch.getPin(SR_Latch::Q), ON);
	EXPECT_EQ(srLatch.getPin(SR_Latch::Q_INV), OFF);
}
