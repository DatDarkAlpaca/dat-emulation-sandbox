#pragma once
#include <array>
#include "Component.h"
#include "gates/Gates.h"

namespace dat
{
	class Decoder2_to_4 : public Component<6>
	{
	public:
		static inline constexpr unsigned F0 = 0;

		static inline constexpr unsigned F1 = 1;

		static inline constexpr unsigned OUT_0 = 2;

		static inline constexpr unsigned OUT_1 = 3;

		static inline constexpr unsigned OUT_2 = 4;

		static inline constexpr unsigned OUT_3 = 5;

	public:
		void process() override
		{
			// Input Aliases:
			State valueF0 = getPin(F0);
			State valueF1 = getPin(F1);

			// Gate Aliases:
			auto& N = notGates;
			auto& A = andGates;

			// N0 - Orange:
			N[0][0] = valueF0;
			N[0].process();
				
			A[0][0] = N[0].getPin(NOT_Gate::OUT);
			A[2][0] = N[0].getPin(NOT_Gate::OUT);

			// N1 - green:
			N[1][0] = valueF1;
			N[1].process();

			A[0][1] = N[1].getPin(NOT_Gate::OUT);
			A[1][0] = N[1].getPin(NOT_Gate::OUT);

			// F0:
			A[1][1] = valueF0;
			A[3][1] = valueF0;

			// F1:
			A[2][1] = valueF1;
			A[3][0] = valueF1;

			for (auto& gate : andGates)
				gate.process();

			setPin(OUT_0, A[0].getPin(AND_Gate::OUT));
			setPin(OUT_1, A[1].getPin(AND_Gate::OUT));
			setPin(OUT_2, A[2].getPin(AND_Gate::OUT));
			setPin(OUT_3, A[3].getPin(AND_Gate::OUT));
		}

	private:
		std::array<NOT_Gate, 2> notGates;
		std::array<AND_Gate, 4> andGates;
	};
}