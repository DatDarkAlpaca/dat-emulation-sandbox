#pragma once
#include <array>
#include "Component.h"
#include "gates/Gates.h"

namespace dat
{
	struct Decoder2_to_4 : public Component<2, 4>
	{
	public:
		void setF0(bool value) { (*this)[0] = value; }

		void setF1(bool value) { (*this)[1] = value; }

	public:
		bool getF0() const { return (*this)[0]; }

		bool getF1() const { return (*this)[1]; }

	public:
		void process() override
		{
			// Input Aliases:
			bool F0 = getF0(), F1 = getF1();

			// Gate Aliases:
			auto& N = notGates;
			auto& A = andGates;

			// N0 - Orange:
			N[0][0] = F0;
			N[0].process();

			A[0][0] = N[0].output();
			A[2][0] = N[0].output();

			// N1 - green:
			N[1][0] = F1;
			N[1].process();

			A[0][1] = N[1].output();
			A[1][0] = N[1].output();

			// F0:
			A[1][1] = F0;
			A[3][1] = F0;

			// F1:
			A[2][1] = F1;
			A[3][0] = F1;

			for (auto& gate : andGates)
				gate.process();

			setOutput(0, A[0].output());
			setOutput(1, A[1].output());
			setOutput(2, A[2].output());
			setOutput(3, A[3].output());
		}

	private:
		std::array<NOT_Gate, 2> notGates;
		std::array<AND_Gate, 4> andGates;
	};
}