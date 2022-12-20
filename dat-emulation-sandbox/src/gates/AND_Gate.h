#pragma once
#include "Component.h"

namespace dat
{
	class AND_Gate : public Component<2, 1>
	{
	public:
		static inline constexpr unsigned IN_0 = 0;

	public:
		void process() override
		{
			setOutput(0, (*this)[0] && (*this)[1]);
		}
	};
}