#pragma once
#include <array>
#include "Component.h"
#include "latches/D_Latch.h"
#include "gates/Gates.h"

namespace dat
{
	class D_FlipFlop : public Component<4>
	{
	public:
		static inline constexpr unsigned D = 0;

		static inline constexpr unsigned CLOCK = 1;

		static inline constexpr unsigned Q = 2;

		static inline constexpr unsigned Q_INV = 3;

	public:
		void process() override
		{
			dLatch.setPin(D_Latch::D, getPin(D));
			dLatch.setPin(D_Latch::ENABLE, getPin(CLOCK));
			dLatch.process();

			setPin(Q, dLatch.getPin(D_Latch::Q));
			setPin(Q_INV, dLatch.getPin(D_Latch::Q_INV));
		}

	private:
		D_Latch dLatch;
		std::array<AND_Gate, 2> andGates;
		NOT_Gate notGate;
	};
}