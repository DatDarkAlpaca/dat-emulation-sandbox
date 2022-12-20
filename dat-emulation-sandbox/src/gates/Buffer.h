#pragma once
#include "State.h"
#include "Component.h"

namespace dat
{
	class Buffer : public Component<2>
	{
	public:
		static inline constexpr unsigned IN = 0;

		static inline constexpr unsigned OUT = 1;

	public:
		void process() override
		{
			setPin(OUT, getPin(IN));
		}
	};
}