#pragma once
#include <array>
#include "Component.h"
#include "SR_Latch.h"
#include "gates/Gates.h"

namespace dat
{
	class D_Latch : public Component<2, 2>
	{
	public:
		State getD() const { return (*this)[0]; }

		void setD(State value) { (*this)[0] = value; }

		State getEnable() const { return (*this)[1]; }

		void setEnable(State value) { (*this)[1] = value; }

	public:
		State getQ() const { return output(0); }

		State getQ_INV() const { return output(1); }

	private:
		void setQ(State value) { setOutput(0, value); }

		void setQ_INV(State value) { setOutput(1, value); }

	public:
		void process() override
		{
			notGate[0] = getD();
			notGate.process();

			andGates[0][0] = notGate.output();
			andGates[0][1] = getEnable();
			andGates[0].process();

			andGates[1][0] = getEnable();
			andGates[1][1] = getD();
			andGates[1].process();

			srLatch.setR(andGates[0].output());
			srLatch.setS(andGates[1].output());
			
			srLatch.process();

			setQ(srLatch.getQ());
			setQ_INV(srLatch.getQ_INV());
		}

	private:
		SR_Latch srLatch;
		std::array<AND_Gate, 2> andGates;
		NOT_Gate notGate;
	};
}