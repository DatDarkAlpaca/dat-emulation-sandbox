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
	using namespace dat;

	SET_PIN(buffer, TriStateBuffer::ENABLE, OFF);

	SET_PIN(buffer, TriStateBuffer::IN, ON);
	buffer.process();
	EXPECT_EQ(buffer.output(), ZERO);

	SET_PIN(buffer, TriStateBuffer::IN, ON);
	buffer.process();
	EXPECT_EQ(buffer.output(), ZERO);
}

TEST_F(Gate_TristateBuffer_Test, Gate_TristateBuffer_Test_1)
{
	using namespace dat;

	SET_PIN(buffer, TriStateBuffer::ENABLE, ON);

	SET_PIN(buffer, TriStateBuffer::IN, ON);
	buffer.process();
	EXPECT_EQ(buffer.output(), ON);

	SET_PIN(buffer, TriStateBuffer::IN, OFF);
	buffer.process();
	EXPECT_EQ(buffer.output(), OFF);
}