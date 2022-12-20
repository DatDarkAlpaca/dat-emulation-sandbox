#include "pch.h"
#include "gates/TristateBuffer.h"

class Gate_TristateBuffer_Test : public testing::Test
{
public:
	void SetUp() override {}
	void TearDown() override { }

public:
	dat::TristateBuffer buffer;
};

TEST_F(Gate_TristateBuffer_Test, Gate_TristateBuffer_Test_0)
{
	using namespace dat;

	buffer.pinOff(TristateBuffer::ENABLE);

	buffer.pinOn(TristateBuffer::IN);
	buffer.process();
	EXPECT_EQ(buffer.getPin(TristateBuffer::OUT), ZERO);

	buffer.pinOff(TristateBuffer::IN);
	buffer.process();
	EXPECT_EQ(buffer.getPin(TristateBuffer::OUT), ZERO);
}

TEST_F(Gate_TristateBuffer_Test, Gate_TristateBuffer_Test_1)
{
	using namespace dat;

	buffer.pinOn(TristateBuffer::ENABLE);

	buffer.pinOn(TristateBuffer::IN);
	buffer.process();
	EXPECT_EQ(buffer.getPin(TristateBuffer::OUT), ON);

	buffer.pinOff(TristateBuffer::IN);
	buffer.process();
	EXPECT_EQ(buffer.getPin(TristateBuffer::OUT), OFF);
}