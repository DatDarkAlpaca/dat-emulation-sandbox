#pragma once
#include <array>
#include "Component.h"
#include "latches/D_Latch.h"
#include "gates/Gates.h"

namespace dat
{
	class D_FlipFlop : public Component<2, 2>
	{
	public:
		bool getD() const { return (*this)[0]; }

		void setD(bool value) { (*this)[0] = value; }

		bool getClock() const { return (*this)[1]; }

		void setClock(bool value) { (*this)[1] = value; }

	public:
		bool getQ() const { return output(0); }

		bool getQ_INV() const { return output(1); }

	private:
		void setQ(bool value) { setOutput(0, value); }

		void setQ_INV(bool value) { setOutput(1, value); }

	public:
		void process() override
		{
			dLatch.setD(getD());
			dLatch.setEnable(getClock());
			dLatch.process();
			
			setQ(dLatch.getQ());
			setQ_INV(dLatch.getQ_INV());
		}

	private:
		D_Latch dLatch;
		std::array<AND_Gate, 2> andGates;
		NOT_Gate notGate;
	};
}