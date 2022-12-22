#pragma once
#include <array>
#include "Component.h"
#include "latches/SR_Latch.h"
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
			nandGateIn[0][NAND_Gate_4IN::IN_0] = OFF;
			nandGateIn[1][NAND_Gate_4IN::IN_2] = ON;
			process();
		}

	public:
		void process() override
		{
			//nandGateIn[0][NAND_Gate_4IN::IN_0] = default;
			nandGateIn[0][NAND_Gate_4IN::IN_1] = getPin(J);
			nandGateIn[0][NAND_Gate_4IN::IN_2] = getPin(CLOCK);
			nandGateIn[0].process();

			nandGateIn[1][NAND_Gate_4IN::IN_0] = getPin(CLOCK);
			nandGateIn[1][NAND_Gate_4IN::IN_1] = getPin(K);
			//nandGateIn[1][NAND_Gate_4IN::IN_2] = default;
			nandGateIn[1].process();

			nandGateOut[0][NAND_Gate::IN_0] = nandGateIn[0][NAND_Gate_4IN::OUT];
			nandGateOut[0][NAND_Gate::IN_1] = nandGateOut[1][NAND_Gate::OUT];
			nandGateOut[0].process();
			
			nandGateOut[1][NAND_Gate::IN_0] = nandGateOut[0][NAND_Gate::OUT];
			nandGateOut[1][NAND_Gate::IN_1] = nandGateIn[1][NAND_Gate_4IN::OUT];
			nandGateOut[1].process();

			nandGateOut[0][NAND_Gate::IN_1] = nandGateOut[1][NAND_Gate::OUT];
			nandGateOut[1][NAND_Gate::IN_0] = nandGateOut[0][NAND_Gate::OUT];

			setPin(Q, nandGateOut[0][NAND_Gate::OUT]);
			setPin(Q_INV, nandGateOut[1][NAND_Gate::OUT]);

			nandGateIn[0][NAND_Gate_4IN::IN_0] = nandGateIn[1][NAND_Gate::OUT];
			nandGateIn[1][NAND_Gate_4IN::IN_2] = nandGateIn[0][NAND_Gate::OUT];
		}

	private:
		std::array<NAND_Gate_4IN, 2> nandGateIn;
		std::array<NAND_Gate, 2> nandGateOut;
	};
}