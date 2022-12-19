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
		State getA() const { return (*this)[0]; }

		void setA(State value) { (*this)[0] = value; }

		State getB() const { return (*this)[1]; }

		void setB(State value) { (*this)[1] = value; }

		State getCarryIn() const { return (*this)[2]; }

		void setCarryIn(State value) { (*this)[2] = value; }

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
			State carryIn = getCarryIn();

			// Inputs:
			halfAdders[0].setA(A);
			halfAdders[0].setB(B);
			halfAdders[0].process();

			halfAdders[1].setA(carryIn);
			halfAdders[1].setB(halfAdders[0].getSum());
			halfAdders[1].process();
			setSum(halfAdders[1].getSum());

			// OR:
			orGate[0] = halfAdders[1].getCarryOut();
			orGate[1] = halfAdders[0].getCarryOut();
			orGate.process();
			setCarryOut(orGate.output());
		}

	private:
		friend class Half_Adder;

	private:
		std::array<Half_Adder, 2> halfAdders;
		OR_Gate orGate;
	};
}