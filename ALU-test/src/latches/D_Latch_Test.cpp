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
	using namespace dat;

	PIN_OFF(dLatch, D_Latch::D); PIN_OFF(dLatch, D_Latch::ENABLE);
	dLatch.process();
	EXPECT_EQ(PIN_VAL(dLatch, D_Latch::Q), ON); EXPECT_EQ(PIN_VAL(dLatch, D_Latch::Q_INV), OFF);

	PIN_ON(dLatch, D_Latch::D); PIN_OFF(dLatch, D_Latch::ENABLE);
	dLatch.process();
	EXPECT_EQ(PIN_VAL(dLatch, D_Latch::Q), ON); EXPECT_EQ(PIN_VAL(dLatch, D_Latch::Q_INV), OFF);

	PIN_ON(dLatch, D_Latch::D); PIN_ON(dLatch, D_Latch::ENABLE);
	dLatch.process();
	EXPECT_EQ(PIN_VAL(dLatch, D_Latch::Q), ON); EXPECT_EQ(PIN_VAL(dLatch, D_Latch::Q_INV), OFF);

	PIN_OFF(dLatch, D_Latch::D); PIN_ON(dLatch, D_Latch::ENABLE);
	dLatch.process();
	EXPECT_EQ(PIN_VAL(dLatch, D_Latch::Q), OFF); EXPECT_EQ(PIN_VAL(dLatch, D_Latch::Q_INV), ON);

	PIN_ON(dLatch, D_Latch::D); PIN_ON(dLatch, D_Latch::ENABLE);
	dLatch.process();
	EXPECT_EQ(PIN_VAL(dLatch, D_Latch::Q), ON); EXPECT_EQ(PIN_VAL(dLatch, D_Latch::Q_INV), OFF);
}
