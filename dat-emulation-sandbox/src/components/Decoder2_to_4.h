#pragma once
#include <array>
#include "Component.h"
#include "gates/Gates.h"

namespace dat
{
	class Decoder2_to_4 : public Component<2, 4>
	{
	public:
		static inline constexpr unsigned F0 = 0;

		static inline constexpr unsigned F1 = 1;

		static inline constexpr unsigned OUT_0 = 0;

		static inline constexpr unsigned OUT_1 = 1;

		static inline constexpr unsigned OUT_2 = 2;

		static inline constexpr unsigned OUT_3 = 3;

	public:
		void process() override
		{
			// Input Aliases:
			State valueF0 = PIN_VAL((*this), F0), valueF1 = PIN_VAL((*this), F1);

			// Gate Aliases:
			auto& N = notGates;
			auto& A = andGates;

			// N0 - Orange:
			N[0][0] = valueF0;
			N[0].process();

			A[0][0] = N[0].output();
			A[2][0] = N[0].output();

			// N1 - green:
			N[1][0] = valueF1;
			N[1].process();

			A[0][1] = N[1].output();
			A[1][0] = N[1].output();

			// F0:
			A[1][1] = valueF0;
			A[3][1] = valueF0;

			// F1:
			A[2][1] = valueF1;
			A[3][0] = valueF1;

			for (auto& gate : andGates)
				gate.process();

			setOutput(OUT_0, A[0].output());
			setOutput(OUT_1, A[1].output());
			setOutput(OUT_2, A[2].output());
			setOutput(OUT_3, A[3].output());
		}

	private:
		std::array<NOT_Gate, 2> notGates;
		std::array<AND_Gate, 4> andGates;
	};
}