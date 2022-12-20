#pragma once
#include <array>
#include "Component.h"
#include "SR_Latch.h"
#include "gates/Gates.h"

namespace dat
{
	class D_Latch : public Component<4>
	{
	public:
		static inline constexpr unsigned D = 0;

		static inline constexpr unsigned ENABLE = 1;

		static inline constexpr unsigned Q = 2;

		static inline constexpr unsigned Q_INV = 3;

	public:
		void process() override
		{
			notGate[0] = getPin(D);
			notGate.process();

			andGates[0][0] = notGate.getPin(NOT_Gate::OUT);
			andGates[0][1] = getPin(ENABLE);
			andGates[0].process();

			andGates[1][0] = getPin(ENABLE);
			andGates[1][1] = getPin(D);
			andGates[1].process();

			srLatch.setPin(SR_Latch::R, andGates[0].getPin(AND_Gate::OUT));
			srLatch.setPin(SR_Latch::S, andGates[1].getPin(AND_Gate::OUT));
			
			srLatch.process();
			
			setPin(Q, srLatch.getPin(Q));
			setPin(Q_INV, srLatch.getPin(Q_INV));
		}

	private:
		SR_Latch srLatch;
		std::array<AND_Gate, 2> andGates;
		NOT_Gate notGate;
	};
}