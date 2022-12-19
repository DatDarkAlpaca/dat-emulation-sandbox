#pragma once
#include "Component.h"
#include "gates/Gates.h"

namespace dat
{
	struct ALU_LogicUnit : public Component<2, 3>
	{
	public:
		void setA(bool value) { (*this)[0] = value; }

		void setB(bool value) { (*this)[1] = value; }

	public:
		bool getA() const { return (*this)[0]; }

		bool getB() const { return (*this)[1]; }

	private:
		void setNotOutput(bool value) { setOutput(0, value); }

		void setOrOutput(bool value) { setOutput(1, value); }

		void setAndOutput(bool value) { setOutput(2, value); }

	public:
		bool getNotOutput() const { return output(0); }

		bool getOrOutput() const { return output(1); }

		bool getAndOutput() const { return output(2); }

	public:
		void process() override
		{
			bool A = getA();
			bool B = getB();

			// Not:
			notGate[0] = A;
			notGate.process();
			setNotOutput(notGate.output());

			// OR:
			orGate[0] = A;
			orGate[1] = B;
			orGate.process();
			setOrOutput(orGate.output());

			// AND:
			andGate[0] = A;
			andGate[1] = B;
			andGate.process();
			setAndOutput(andGate.output());
		}

	private:
		NOT_Gate notGate;
		OR_Gate orGate;
		AND_Gate andGate;
	};
}