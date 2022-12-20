#pragma once
#include <array>
#include "Component.h"
#include "gates/Gates.h"

namespace dat
{
	class Half_Adder : public Component<4>
	{
	public:
		static inline constexpr unsigned A = 0;

		static inline constexpr unsigned B = 1;

		static inline constexpr unsigned SUM = 2;

		static inline constexpr unsigned CARRY_OUT = 3;

	public:
		void process() override
		{
			State valueA = getPin(A);
			State valueB = getPin(B);

			// A:
			xorGate[0] = valueA;
			andGate[0] = valueA;

			// B:
			xorGate[1] = valueB;
			andGate[1] = valueB;

			xorGate.process();
			andGate.process();

			setPin(SUM, xorGate.getPin(XOR_Gate::OUT));
			setPin(CARRY_OUT, andGate.getPin(XOR_Gate::OUT));
		}

	private:
		XOR_Gate xorGate;
		AND_Gate andGate;
	};
}