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
	buffer.setInput(ON);
	buffer.process();
	EXPECT_EQ(buffer.output(), ON);
}

TEST_F(Gate_Buffer_Test, Gate_Buffer_Test_1)
{
	buffer.setInput(OFF);
	buffer.process();
	EXPECT_EQ(buffer.output(), OFF);
}
