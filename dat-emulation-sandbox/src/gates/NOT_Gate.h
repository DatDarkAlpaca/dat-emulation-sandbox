#pragma once
#include "Component.h"

namespace dat
{
	class NOT_Gate : public Component<1, 1>
	{
	public:
		static inline constexpr unsigned IN = 0;

		static inline constexpr unsigned OUT = 0;

	public:
		void process() override
		{
			setOutput(OUT, !(*this)[IN]);
		}
	};
}