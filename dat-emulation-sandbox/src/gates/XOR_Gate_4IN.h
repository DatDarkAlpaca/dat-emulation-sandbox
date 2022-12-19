#pragma once
#include "Component.h"

namespace dat
{
	class XOR_Gate_4IN : public Component<4, 1>
	{
	public:
		void process() override
		{
			setOutput(0, (*this)[0] ^ (*this)[1] ^ (*this)[2] ^ (*this)[3]);
		}
	};
}