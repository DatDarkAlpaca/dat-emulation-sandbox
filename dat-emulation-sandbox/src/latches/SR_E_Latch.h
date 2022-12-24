#pragma once
#include <array>
#include "Component.h"
#include "gates/Gates.h"
#include "SR_Latch.h"

namespace dat
{
	class SR_E_Latch : public Component<5>
	{
	public:
		static inline constexpr unsigned R = 0;

		static inline constexpr unsigned S = 1;

		static inline constexpr unsigned E = 2;

		static inline constexpr unsigned Q = 3;

		static inline constexpr unsigned Q_INV = 4;

	public:
		SR_E_Latch()
		{
			process();
		}

	public:
		void process() override
		{
			andGates[0][0] = getPin(R);
			andGates[0][1] = getPin(E);
			andGates[0].process();

			andGates[1][0] = getPin(E);
			andGates[1][1] = getPin(S);
			andGates[1].process();

			latch[SR_Latch::R] = andGates[0][AND_Gate::OUT];
			latch[SR_Latch::S] = andGates[1][AND_Gate::OUT];
			latch.process();

			setPin(Q, latch[SR_Latch::Q]);
			setPin(Q_INV, latch[SR_Latch::Q_INV]);
		}

	private:
		std::array<AND_Gate, 2> andGates;
		SR_Latch latch;
	};
}