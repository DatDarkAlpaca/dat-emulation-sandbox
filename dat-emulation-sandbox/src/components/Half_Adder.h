#pragma once
#include <array>
#include "Component.h"
#include "gates/Gates.h"

namespace dat
{
	class Half_Adder : public Component<2, 2>
	{
	public:
		static inline constexpr unsigned A = 0;

		static inline constexpr unsigned B = 1;

		static inline constexpr unsigned SUM = 0;

		static inline constexpr unsigned CARRY_OUT = 1;

	public:
		void process() override
		{
			State valueA = PIN_VAL((*this), A);
			State valueB = PIN_VAL((*this), B);

			// A:
			xorGate[0] = valueA;
			andGate[0] = valueA;

			// B:
			xorGate[1] = valueB;
			andGate[1] = valueB;

			xorGate.process();
			andGate.process();

			SET_PIN((*this), SUM, xorGate.output());
			SET_PIN((*this), CARRY_OUT, andGate.output());
		}

	private:
		XOR_Gate xorGate;
		AND_Gate andGate;
	};
}