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

	dLatch.pinOff(D_Latch::D);
	dLatch.pinOff(D_Latch::ENABLE);
	dLatch.process();
	EXPECT_EQ(dLatch.getPin(D_Latch::Q), ON); 
	EXPECT_EQ(dLatch.getPin(D_Latch::Q_INV), OFF);

	dLatch.pinOn(D_Latch::D);
	dLatch.pinOff(D_Latch::ENABLE);
	dLatch.process();
	EXPECT_EQ(dLatch.getPin(D_Latch::Q), ON); 
	EXPECT_EQ(dLatch.getPin(D_Latch::Q_INV), OFF);

	dLatch.pinOn(D_Latch::D);
	dLatch.pinOn(D_Latch::ENABLE);
	dLatch.process();
	EXPECT_EQ(dLatch.getPin(D_Latch::Q), ON); 
	EXPECT_EQ(dLatch.getPin(D_Latch::Q_INV), OFF);

	dLatch.pinOff(D_Latch::D);
	dLatch.pinOn(D_Latch::ENABLE);
	dLatch.process();
	EXPECT_EQ(dLatch.getPin(D_Latch::Q), OFF); 
	EXPECT_EQ(dLatch.getPin(D_Latch::Q_INV), ON);

	dLatch.pinOn(D_Latch::D);
	dLatch.pinOn(D_Latch::ENABLE);
	dLatch.process();
	EXPECT_EQ(dLatch.getPin(D_Latch::Q), ON); 
	EXPECT_EQ(dLatch.getPin(D_Latch::Q_INV), OFF);
}
