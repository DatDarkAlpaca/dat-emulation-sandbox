#pragma once
#include "Component.h"
#include "gates/Gates.h"

namespace dat
{
	class ALU_LogicUnit : public Component<2, 3>
	{
	public:
		void setA(State value) { (*this)[0] = value; }

		void setB(State value) { (*this)[1] = value; }

	public:
		State getA() const { return (*this)[0]; }

		State getB() const { return (*this)[1]; }

	private:
		void setNotOutput(State value) { setOutput(0, value); }

		void setOrOutput(State value) { setOutput(1, value); }

		void setAndOutput(State value) { setOutput(2, value); }

	public:
		State getNotOutput() const { return output(0); }

		State getOrOutput() const { return output(1); }

		State getAndOutput() const { return output(2); }

	public:
		void process() override
		{
			State A = getA();
			State B = getB();

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