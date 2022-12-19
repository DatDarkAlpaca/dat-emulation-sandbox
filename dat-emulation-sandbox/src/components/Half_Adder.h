#pragma once
#include <array>
#include "Component.h"
#include "gates/Gates.h"

namespace dat
{
	class Half_Adder : public Component<2, 2>
	{
	public:
		State getA() const { return (*this)[0]; }

		void setA(State value) { (*this)[0] = value; }

		State getB() const { return (*this)[1]; }

		void setB(State value) { (*this)[1] = value; }

	public:
		State getSum() const { return output(0); }

		State getCarryOut() const { return output(1); }

	private:
		void setSum(State value) { setOutput(0, value); }

		void setCarryOut(State value) { setOutput(1, value); }

	public:
		void process() override
		{
			State A = getA();
			State B = getB();

			// A:
			xorGate[0] = A;
			andGate[0] = A;

			// B:
			xorGate[1] = B;
			andGate[1] = B;

			xorGate.process();
			andGate.process();

			setSum(xorGate.output());
			setCarryOut(andGate.output());
		}

	private:
		XOR_Gate xorGate;
		AND_Gate andGate;
	};
}