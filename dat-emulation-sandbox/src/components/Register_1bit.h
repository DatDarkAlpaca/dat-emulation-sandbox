#pragma once
#include <array>
#include "Component.h"
#include "gates/TristateBuffer.h"
#include "flip_flops/D_FlipFlop.h"

namespace dat 
{
	class Register_1bit : public Component<4, 1>
	{
	public:
		Register_1bit()
		{
			andGates[0][0] = OFF;
		}

	public:
		State getLoad() const { return (*this)[0]; }

		void setLoad(State value) { (*this)[0] = value; }

		State getD1() const { return (*this)[1]; }

		void setD1(State value) { (*this)[1] = value; }

		State getClock() const { return (*this)[2]; }

		void setClock(State value) { (*this)[2] = value; }

		State getEnable() const { return (*this)[3]; }

		void setEnable(State value) { (*this)[3] = value; }

	public:
		void process() override
		{
			notGate[0] = getLoad();
			notGate.process();

			andGates[0][1] = notGate.output();
			andGates[0].process();

			andGates[1][0] = getLoad();
			andGates[1][1] = getD1();
			andGates[1].process();

			orGate[0] = andGates[0].output();
			orGate[1] = andGates[1].output();
			orGate.process();

			flipFlop.setD(orGate.output());
			flipFlop.setClock(getClock());
			flipFlop.process();

			andGates[0][1] = flipFlop.getQ();

			triBuffer.setEnable(getEnable());
			triBuffer.setInput(flipFlop.getQ());
			triBuffer.process();

			setOutput(0, triBuffer.output());
		}

	public:
		std::array<AND_Gate, 2> andGates;
		D_FlipFlop flipFlop;
		NOT_Gate notGate;
		OR_Gate orGate;
		TriStateBuffer triBuffer;
	};
}