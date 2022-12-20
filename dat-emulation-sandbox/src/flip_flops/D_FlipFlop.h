#pragma once
#include <array>
#include "Component.h"
#include "latches/D_Latch.h"
#include "gates/Gates.h"

namespace dat
{
	class D_FlipFlop : public Component<2, 2>
	{
	public:
		static inline constexpr unsigned D = 0;

		static inline constexpr unsigned CLOCK = 1;

		static inline constexpr unsigned Q = 0;

		static inline constexpr unsigned Q_INV = 1;

	public:
		void process() override
		{
			
			SET_PIN(dLatch, D_Latch::D, PIN_VAL((*this), D));
			SET_PIN(dLatch, D_Latch::ENABLE, PIN_VAL((*this), CLOCK));
			dLatch.process();

			SET_PIN((*this), Q, PIN_VAL(dLatch, D_Latch::Q));
			SET_PIN((*this), Q_INV, PIN_VAL(dLatch, D_Latch::Q_INV));
		}

	private:
		D_Latch dLatch;
		std::array<AND_Gate, 2> andGates;
		NOT_Gate notGate;
	};
}