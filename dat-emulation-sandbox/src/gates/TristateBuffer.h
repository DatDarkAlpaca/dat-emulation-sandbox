#pragma once
#include "Component.h"

namespace dat
{
	class TristateBuffer : public Component<3>
	{
	public:
		static inline constexpr unsigned IN = 0;

		static inline constexpr unsigned ENABLE = 1;

		static inline constexpr unsigned OUT = 2;

	public:
		void process() override
		{
			if (!getPin(ENABLE))
				setPin(OUT, ZERO);
			else
				setPin(OUT, getPin(IN));
		}
	};
}