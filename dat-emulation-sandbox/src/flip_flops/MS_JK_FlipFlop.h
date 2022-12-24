#pragma once
#include <array>
#include "Component.h"
#include "gates/Gates.h"
#include "flip_flops/JK_FlipFlop.h"

namespace dat
{
	class MS_JK_FlipFlop : public Component<5>
	{
	public:
		static inline constexpr unsigned J = 0;

		static inline constexpr unsigned K = 1;

		static inline constexpr unsigned CLOCK = 2;

		static inline constexpr unsigned Q = 3;

		static inline constexpr unsigned Q_INV = 4;

	public:
		MS_JK_FlipFlop()
		{
			pinOn(Q);
			process();
		}

	public:
		void process() override
		{
			inAndGates[0][0] = getPin(Q_INV);
			inAndGates[0][1] = getPin(J);
			inAndGates[0][2] = getPin(CLOCK);
			inAndGates[0].process();

			inAndGates[1][0] = getPin(CLOCK);
			inAndGates[1][1] = getPin(K);
			inAndGates[1][2] = getPin(Q);
			inAndGates[1].process();

			latch[0][SR_Latch::S] = inAndGates[0][AND_Gate_3IN::OUT];
			latch[0][SR_Latch::R] = inAndGates[1][AND_Gate_3IN::OUT];
			latch[0].process();

			notGate[0] = getPin(CLOCK);
			notGate.process();

			outAndGates[0][0] = latch[0][SR_Latch::Q_INV];
			outAndGates[0][1] = notGate[NOT_Gate::OUT];
			outAndGates[0].process();

			outAndGates[1][0] = notGate[NOT_Gate::OUT];
			outAndGates[1][1] = latch[0][SR_Latch::Q];
			outAndGates[1].process();

			latch[1][SR_Latch::R] = outAndGates[0][AND_Gate::OUT];
			latch[1][SR_Latch::S] = outAndGates[1][AND_Gate::OUT];
			latch[1].process();

			setPin(Q, latch[1][SR_Latch::Q]);
			setPin(Q_INV, latch[1][SR_Latch::Q_INV]);
		}

	private:
		std::array<AND_Gate_3IN, 2> inAndGates;
		std::array<AND_Gate, 2> outAndGates;
		std::array<SR_Latch, 2> latch;
		NOT_Gate notGate;
	};
}