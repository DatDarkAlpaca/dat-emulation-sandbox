#pragma once
#include <array>
#include "Component.h"
#include "SR_Latch.h"
#include "gates/Gates.h"

namespace dat
{
	class D_Latch : public Component<2, 2>
	{
	public:
		static inline constexpr unsigned D = 0;

		static inline constexpr unsigned ENABLE = 1;

		static inline constexpr unsigned Q = 0;

		static inline constexpr unsigned Q_INV = 1;

	public:
		void process() override
		{
			notGate[0] = PIN_VAL((*this), D);
			notGate.process();

			andGates[0][0] = notGate.output();
			andGates[0][1] = PIN_VAL((*this), ENABLE);
			andGates[0].process();

			andGates[1][0] = PIN_VAL((*this), ENABLE);
			andGates[1][1] = PIN_VAL((*this), D);
			andGates[1].process();

			SET_PIN(srLatch, SR_Latch::R, andGates[0].output());
			SET_PIN(srLatch, SR_Latch::S, andGates[1].output());
			
			srLatch.process();
			
			SET_PIN((*this), Q, PIN_VAL(srLatch, SR_Latch::Q));
			SET_PIN((*this), Q_INV, PIN_VAL(srLatch, SR_Latch::Q_INV));
		}

	private:
		SR_Latch srLatch;
		std::array<AND_Gate, 2> andGates;
		NOT_Gate notGate;
	};
}