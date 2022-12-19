#pragma once
#include <array>
#include "Component.h"
#include "gates/Gates.h"

namespace dat
{
	struct Half_Adder : public Component<2, 2>
	{
	public:
		bool getA() const { return (*this)[0]; }

		void setA(bool value) { (*this)[0] = value; }

		bool getB() const { return (*this)[1]; }

		void setB(bool value) { (*this)[1] = value; }

	public:
		bool getSum() const { return output(0); }

		bool getCarryOut() const { return output(1); }

	private:
		void setSum(bool value) { setOutput(0, value); }

		void setCarryOut(bool value) { setOutput(1, value); }

	public:
		void process() override
		{
			bool A = getA();
			bool B = getB();

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