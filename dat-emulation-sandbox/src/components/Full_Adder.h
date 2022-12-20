#pragma once
#include <array>
#include "Component.h"
#include "gates/Gates.h"
#include "Half_Adder.h"

namespace dat
{
	class Full_Adder : public Component<5>
	{
	public:
		static inline constexpr unsigned A = 0;

		static inline constexpr unsigned B = 1;

		static inline constexpr unsigned CARRY_IN = 2;

		static inline constexpr unsigned SUM = 3;

		static inline constexpr unsigned CARRY_OUT = 4;

	public:
		void process() override
		{
			
			State valueA = getPin(A);
			State valueB = getPin(B);
			State carryIn = getPin(CARRY_IN);

			// Inputs:
			halfAdders[0].setPin(Half_Adder::A, valueA);
			halfAdders[0].setPin(Half_Adder::B, valueB);
			halfAdders[0].process();

			halfAdders[1].setPin(Half_Adder::A, carryIn);
			halfAdders[1].setPin(Half_Adder::B, halfAdders[0].getPin(Half_Adder::SUM));
			halfAdders[1].process();

			setPin(SUM, halfAdders[1].getPin(Half_Adder::SUM));

			// OR:
			orGate[0] = halfAdders[1].getPin(Half_Adder::CARRY_OUT);
			orGate[1] = halfAdders[0].getPin(Half_Adder::CARRY_OUT);
			orGate.process();

			setPin(CARRY_OUT, orGate.getPin(OR_Gate::OUT));
		}

	private:
		friend class Half_Adder;

	private:
		std::array<Half_Adder, 2> halfAdders;
		OR_Gate orGate;
	};
}