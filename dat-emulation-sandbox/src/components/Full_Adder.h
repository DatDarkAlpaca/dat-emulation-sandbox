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
		bool getA() const { return (*this)[0]; }

		void setA(bool value) { (*this)[0] = value; }

		bool getB() const { return (*this)[1]; }

		void setB(bool value) { (*this)[1] = value; }

		bool getCarryIn() const { return (*this)[2]; }

		void setCarryIn(bool value) { (*this)[2] = value; }

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
			bool carryIn = getCarryIn();

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