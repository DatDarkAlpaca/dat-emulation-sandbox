#pragma once
#include "Component.h"

namespace dat
{
	class AND_Gate_3IN : public Component<4>
	{
	public:
		static inline constexpr unsigned IN_0 = 0;

		static inline constexpr unsigned IN_1 = 1;

		static inline constexpr unsigned IN_2 = 2;

		static inline constexpr unsigned OUT = 3;

	public:
		void process() override
		{
			setPin(OUT, getPin(IN_0) && getPin(IN_1) && getPin(IN_2));
		}
	};
}