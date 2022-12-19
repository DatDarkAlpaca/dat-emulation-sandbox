#pragma once
#include "Component.h"

namespace dat
{
	class NOT_Gate : public Component<1, 1>
	{
	public:
		void process() override
		{
			setOutput(0, !(*this)[0]);
		}
	};
}