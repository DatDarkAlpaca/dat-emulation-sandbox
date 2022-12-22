#pragma once
#include "Component.h"

namespace dat
{
	class NAND_Gate_4IN : public Component<3>
	{
	public:
		static inline constexpr unsigned IN_0 = 0;

		static inline constexpr unsigned IN_1 = 1;

		static inline constexpr unsigned IN_2 = 2;

		static inline constexpr unsigned OUT = 3;

	public:
		void process() override
		{
			setPin(OUT, !(getPin(IN_0) && getPin(IN_1) && getPin(IN_2)));
		}
	};
}