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

	PIN_OFF(srLatch, SR_Latch::R); PIN_OFF(srLatch, SR_Latch::S);
	srLatch.process();
	EXPECT_EQ(PIN_VAL(srLatch, SR_Latch::Q), ON); EXPECT_EQ(PIN_VAL(srLatch, SR_Latch::Q_INV), OFF);

	PIN_ON(srLatch, SR_Latch::R); PIN_OFF(srLatch, SR_Latch::S);
	srLatch.process();
	EXPECT_EQ(PIN_VAL(srLatch, SR_Latch::Q), OFF); EXPECT_EQ(PIN_VAL(srLatch, SR_Latch::Q_INV), ON);

	PIN_OFF(srLatch, SR_Latch::R); PIN_OFF(srLatch, SR_Latch::S);
	srLatch.process();
	EXPECT_EQ(PIN_VAL(srLatch, SR_Latch::Q), OFF); EXPECT_EQ(PIN_VAL(srLatch, SR_Latch::Q_INV), ON);

	PIN_OFF(srLatch, SR_Latch::R); PIN_ON(srLatch, SR_Latch::S);
	srLatch.process();
	EXPECT_EQ(PIN_VAL(srLatch, SR_Latch::Q), ON); EXPECT_EQ(PIN_VAL(srLatch, SR_Latch::Q_INV), OFF);
}
