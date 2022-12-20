#pragma once
#include "Component.h"

namespace dat
{
	class XOR_Gate_4IN : public Component<4, 1>
	{
	public:
		static inline constexpr unsigned IN_0 = 0;

		static inline constexpr unsigned IN_1 = 1;

		static inline constexpr unsigned IN_2 = 2;

		static inline constexpr unsigned IN_3 = 3;

		static inline constexpr unsigned OUT = 0;

	public:
		void process() override
		{
			setOutput(OUT, (*this)[IN_0] ^ (*this)[IN_1] ^ (*this)[IN_2] ^ (*this)[IN_3]);
		}
	};
}