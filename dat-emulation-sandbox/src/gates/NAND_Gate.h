#pragma once
#include "Component.h"

namespace dat
{
	class NAND_Gate : public Component<2, 1>
	{
	public:
		void process() override
		{
			setOutput(0, !((*this)[0] && (*this)[1]));
		}
	};
}