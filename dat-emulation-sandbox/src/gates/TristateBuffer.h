#pragma once
#include "Component.h"

namespace dat
{
	class TriStateBuffer : public Component<2, 1>
	{
	public:
		static inline constexpr unsigned IN = 0;

		static inline constexpr unsigned ENABLE = 1;

		static inline constexpr unsigned OUT = 0;

	public:
		void process() override
		{
			if (!PIN_VAL((*this), ENABLE))
				setOutput(0, ZERO);
			else
				setOutput(0, PIN_VAL((*this), IN));
		}
	};
}