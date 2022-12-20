#pragma once
#include <array>
#include "Component.h"
#include "gates/Gates.h"

namespace dat
{
	class SR_Latch : public Component<2, 2>
	{
	public:
		static inline constexpr unsigned R = 0;

		static inline constexpr unsigned S = 1;

		static inline constexpr unsigned Q = 0;

		static inline constexpr unsigned Q_INV = 1;

	public:
		SR_Latch()
		{
			// Q initially open:
			norGates[0][1] = OFF;
		}

	public:
		void process() override
		{
			norGates[0][0] = PIN_VAL((*this), R);
			norGates[0].process();

			norGates[1][0] = norGates[0].output();
			norGates[1][1] = PIN_VAL((*this), S);
			norGates[1].process();

			norGates[0][1] = norGates[1].output();
			norGates[0].process();

			SET_PIN((*this), Q, norGates[0].output());
			SET_PIN((*this), Q_INV, norGates[1].output());
		}

	private:
		std::array<NOR_Gate, 2> norGates;
	};
}