#pragma once
#include "State.h"
#include "Component.h"

namespace dat
{
	class Buffer : public Component<1, 1>
	{
	public:
		static inline constexpr unsigned IN = 0;

		static inline constexpr unsigned OUT = 0;

	public:
		void process() override
		{
			setOutput(OUT, PIN_VAL((*this), IN));
		}
	};
}