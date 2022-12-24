#pragma once
#include <array>
#include "Component.h"
#include "latches/SR_E_Latch.h"
#include "gates/Gates.h"

namespace dat
{
	class JK_FlipFlop : public Component<5>
	{
	public:
		static inline constexpr unsigned J = 0;

		static inline constexpr unsigned K = 1;

		static inline constexpr unsigned CLOCK = 2;

		static inline constexpr unsigned Q = 3;

		static inline constexpr unsigned Q_INV = 4;

	public:
		JK_FlipFlop()
		{
			pinOn(Q);
			process();
		}

	public:
		void process() override
		{
			andGates[0][0] = getPin(Q);
			andGates[0][1] = getPin(K);
			andGates[0][2] = getPin(CLOCK);
			andGates[0].process();

			andGates[1][0] = getPin(CLOCK);
			andGates[1][1] = getPin(J);
			andGates[1][2] = getPin(Q_INV);
			andGates[1].process();

			latch[SR_Latch::R] = andGates[0][AND_Gate_3IN::OUT];
			latch[SR_Latch::S] = andGates[1][AND_Gate_3IN::OUT];
			latch.process();

			setPin(Q, latch[SR_Latch::Q]);
			setPin(Q_INV, latch[SR_Latch::Q_INV]);
		}

	private:
		std::array<AND_Gate_3IN, 2> andGates;
		SR_Latch latch;
	};
}