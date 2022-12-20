#pragma once
#include "Component.h"
#include "gates/Gates.h"

namespace dat
{
	class ALU_LogicUnit : public Component<5>
	{
	public:
		static inline constexpr unsigned A = 0;

		static inline constexpr unsigned B = 1;

		static inline constexpr unsigned NOT_OUT = 2;

		static inline constexpr unsigned OR_OUT = 3;

		static inline constexpr unsigned AND_OUT = 4;

	public:
		void process() override
		{
			State valueA = getPin(A);
			State valueB = getPin(B);

			// Not:
			notGate[0] = valueA;
			notGate.process();
			setPin(NOT_OUT, notGate.getPin(NOT_Gate::OUT));

			// OR:
			orGate[0] = valueA;
			orGate[1] = valueB;
			orGate.process();
			setPin(OR_OUT, orGate.getPin(OR_Gate::OUT));

			// AND:
			andGate[0] = valueA;
			andGate[1] = valueB;
			andGate.process();
			setPin(AND_OUT, andGate.getPin(AND_Gate::OUT));
		}

	private:
		NOT_Gate notGate;
		OR_Gate orGate;
		AND_Gate andGate;
	};
}