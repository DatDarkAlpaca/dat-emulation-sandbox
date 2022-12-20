#pragma once
#include <array>
#include "Component.h"
#include "gates/Gates.h"

namespace dat
{
	class SR_Latch : public Component<4>
	{
	public:
		static inline constexpr unsigned R = 0;

		static inline constexpr unsigned S = 1;

		static inline constexpr unsigned Q = 2;

		static inline constexpr unsigned Q_INV = 3;

	public:
		SR_Latch()
		{
			// Q initially open:
			norGates[0][1] = OFF;
		}

	public:
		void process() override
		{
			norGates[0][0] = getPin(R);
			norGates[0].process();

			norGates[1][0] = norGates[0].getPin(NOR_Gate::OUT);
			norGates[1][1] = getPin(S);
			norGates[1].process();

			norGates[0][1] = norGates[1].getPin(NOR_Gate::OUT);
			norGates[0].process();

			setPin(Q, norGates[0].getPin(NOR_Gate::OUT));
			setPin(Q_INV, norGates[1].getPin(NOR_Gate::OUT));
		}

	private:
		std::array<NOR_Gate, 2> norGates;
	};
}