#include "pch.h"
#include "flip_flops/JK_FlipFlop.h"

class JK_FlipFlop_Test : public testing::Test
{
public:
	void SetUp() override {}
	void TearDown() override { }

public:
	dat::JK_FlipFlop jk;
};

TEST_F(JK_FlipFlop_Test, JK_FlipFlop_Test_Boot)
{
	using namespace dat;

	EXPECT_EQ(jk[JK_FlipFlop::Q], ON);
	EXPECT_EQ(jk[JK_FlipFlop::Q_INV], OFF);
}

TEST_F(JK_FlipFlop_Test, JK_FlipFlop_Test_Zero_Clock)
{
	using namespace dat;

	jk[JK_FlipFlop::CLOCK] = OFF;
	jk.process();

	EXPECT_EQ(jk[JK_FlipFlop::Q], ON);
	EXPECT_EQ(jk[JK_FlipFlop::Q_INV], OFF);
}

TEST_F(JK_FlipFlop_Test, JK_FlipFlop_Test_Clock_Without_Input)
{
	using namespace dat;

	jk[JK_FlipFlop::J] = OFF;
	jk[JK_FlipFlop::K] = OFF;

	jk[JK_FlipFlop::CLOCK] = ON;
	jk.process();

	EXPECT_EQ(jk[JK_FlipFlop::Q], ON);
	EXPECT_EQ(jk[JK_FlipFlop::Q_INV], OFF);
}

TEST_F(JK_FlipFlop_Test, JK_FlipFlop_Test_Zero_0)
{
	using namespace dat;

	// Doesn't Change:
	jk[JK_FlipFlop::CLOCK] = ON;
	jk[JK_FlipFlop::J] = OFF;
	jk[JK_FlipFlop::K] = OFF;
	jk.process();
	EXPECT_EQ(jk[JK_FlipFlop::Q], ON);
	EXPECT_EQ(jk[JK_FlipFlop::Q_INV], OFF);

	// Sets Q_INV:
	jk[JK_FlipFlop::CLOCK] = ON;
	jk[JK_FlipFlop::J] = OFF;
	jk[JK_FlipFlop::K] = ON;
	jk.process();
	EXPECT_EQ(jk[JK_FlipFlop::Q], ON);
	EXPECT_EQ(jk[JK_FlipFlop::Q_INV], ON);

	jk.process();
	EXPECT_EQ(jk[JK_FlipFlop::Q], OFF);
	EXPECT_EQ(jk[JK_FlipFlop::Q_INV], ON);
}
