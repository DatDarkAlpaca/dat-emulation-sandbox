#pragma once
#include "Component.h"

namespace dat
{
	class NAND_Gate : public Component<2, 1>
	{
	public:
		static inline constexpr unsigned IN_0 = 0;

		static inline constexpr unsigned IN_1 = 1;

		static inline constexpr unsigned OUT = 0;

	public:
		void process() override
		{
			setOutput(OUT, !((*this)[IN_0] && (*this)[IN_1]));
		}
	};
}