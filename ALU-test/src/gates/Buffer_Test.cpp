#include "pch.h"
#include "gates/Buffer.h"

class Gate_Buffer_Test : public testing::Test
{
public:
	void SetUp() override {}
	void TearDown() override { }

public:
	dat::Buffer buffer;
};

TEST_F(Gate_Buffer_Test, Gate_Buffer_Test_0)
{
	using namespace dat;

	buffer.setPin(Buffer::IN, ON);
	buffer.process();

	EXPECT_EQ(buffer.getPin(Buffer::OUT), ON);
}

TEST_F(Gate_Buffer_Test, Gate_Buffer_Test_1)
{
	using namespace dat;

	buffer.setPin(Buffer::IN, OFF);
	buffer.process();

	EXPECT_EQ(buffer.getPin(Buffer::OUT), OFF);
}
