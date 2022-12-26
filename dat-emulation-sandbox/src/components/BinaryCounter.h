#pragma once
#include <array>
#include "Component.h"
#include "gates/Gates.h"
#include "flip_flops/MS_JK_FlipFlop.h"

#define BIT_SIZE 8

namespace dat
{
	using BinaryCounter_1bit = MS_JK_FlipFlop;

	class BinaryCounter : public Component<9>
	{
	public:
		static inline constexpr unsigned CLOCK = 0;

		static inline constexpr unsigned OUT[BIT_SIZE] = {
			1, 2, 3, 4, 5, 6, 7, 8
		};

	public:
		BinaryCounter()
		{
			for (auto& flipFlop : flipFlops)
			{
				flipFlop[MS_JK_FlipFlop::J] = ON;
				flipFlop[MS_JK_FlipFlop::K] = ON;
			}
		}

	public:
		void process() override
		{
			for (size_t i = 0; i < flipFlops.size(); ++i)
			{
				if (i == 0)
					flipFlops[i][BinaryCounter_1bit::CLOCK] = getPin(CLOCK);
				else
					flipFlops[i][BinaryCounter_1bit::CLOCK] = flipFlops[i - 1][BinaryCounter_1bit::Q];
			
				flipFlops[i].process();

				setPin(OUT[BIT_SIZE - 1 - i], flipFlops[i][BinaryCounter_1bit::Q]);
			}
		}

	private:
		std::array<BinaryCounter_1bit, BIT_SIZE> flipFlops;
	};
}