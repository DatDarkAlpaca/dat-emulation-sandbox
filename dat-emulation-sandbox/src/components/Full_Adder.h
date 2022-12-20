#pragma once
#include <array>
#include "Component.h"
#include "gates/Gates.h"
#include "Half_Adder.h"

namespace dat
{
	class Full_Adder : public Component<3, 2>
	{
	public:
		static inline constexpr unsigned A = 0;

		static inline constexpr unsigned B = 1;

		static inline constexpr unsigned CARRY_IN = 2;

		static inline constexpr unsigned SUM = 0;

		static inline constexpr unsigned CARRY_OUT = 1;

	public:
		void process() override
		{
			State valueA = PIN_VAL((*this), A);
			State valueB = PIN_VAL((*this), B);
			State carryIn = PIN_VAL((*this), CARRY_IN);

			// Inputs:
			SET_PIN(halfAdders[0], Half_Adder::A, valueA);
			SET_PIN(halfAdders[0], Half_Adder::B, valueB);
			halfAdders[0].process();

			SET_PIN(halfAdders[1], Half_Adder::A, carryIn);
			SET_PIN(halfAdders[1], Half_Adder::B, PIN_VAL(halfAdders[0], Half_Adder::SUM));
			halfAdders[1].process();

			SET_PIN((*this), SUM, PIN_VAL(halfAdders[1], Half_Adder::SUM));

			// OR:
			orGate[0] = PIN_VAL(halfAdders[1], Half_Adder::CARRY_OUT);
			orGate[1] = PIN_VAL(halfAdders[0], Half_Adder::CARRY_OUT);
			orGate.process();

			SET_PIN((*this), CARRY_OUT, orGate.output());
		}

	private:
		friend class Half_Adder;

	private:
		std::array<Half_Adder, 2> halfAdders;
		OR_Gate orGate;
	};
}