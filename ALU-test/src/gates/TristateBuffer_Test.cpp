#include "pch.h"
#include "gates/TristateBuffer.h"

class Gate_TristateBuffer_Test : public testing::Test
{
public:
	void SetUp() override {}
	void TearDown() override { }

public:
	dat::TriStateBuffer buffer;
};

TEST_F(Gate_TristateBuffer_Test, Gate_TristateBuffer_Test_0)
{
	buffer.setEnable(OFF);

	buffer.setInput(ON);
	buffer.process();
	EXPECT_EQ(buffer.output(), ZERO);

	buffer.setInput(ON);
	buffer.process();
	EXPECT_EQ(buffer.output(), ZERO);
}

TEST_F(Gate_TristateBuffer_Test, Gate_TristateBuffer_Test_1)
{
	buffer.setEnable(ON);

	buffer.setInput(ON);
	buffer.process();
	EXPECT_EQ(buffer.output(), ON);

	buffer.setInput(OFF);
	buffer.process();
	EXPECT_EQ(buffer.output(), OFF);
}