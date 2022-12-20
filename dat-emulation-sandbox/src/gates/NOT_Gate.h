#pragma once
#include "Component.h"

namespace dat
{
	class NOT_Gate : public Component<2>
	{
	public:
		static inline constexpr unsigned IN = 0;

		static inline constexpr unsigned OUT = 1;

	public:
		void process() override
		{
			setPin(OUT, !getPin(IN));
		}
	};
}