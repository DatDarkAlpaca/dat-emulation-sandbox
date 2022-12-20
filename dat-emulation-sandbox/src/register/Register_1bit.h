#pragma once
#include <array>
#include "Component.h"
#include "gates/TristateBuffer.h"
#include "flip_flops/D_FlipFlop.h"

namespace dat 
{
	//class Register_1bit : public Component<4, 1>
	//{
	//public:
	//	static inline constexpr unsigned LOAD = 0;

	//	static inline constexpr unsigned D1 = 1;

	//	static inline constexpr unsigned CLK = 2;

	//	static inline constexpr unsigned ENABLE = 3;

	//	static inline constexpr unsigned OUT = 0;

	//public:
	//	Register_1bit()
	//	{
	//		SET_PIN((*this), ENABLE, OFF);
	//		SET_PIN((*this), LOAD, OFF);

	//		andGates[0][0] = ON;
	//	}

	//public:
	//	void process() override
	//	{
	//		using namespace dat;

	//		notGate[0] = PIN_VAL((*this), LOAD);
	//		notGate.process();

	//		// andGates[0][0] = default;
	//		andGates[0][1] = notGate.output();
	//		andGates[0].process();

	//		andGates[1][0] = PIN_VAL((*this), LOAD);
	//		andGates[1][1] = PIN_VAL((*this), D1);
	//		andGates[1].process();

	//		orGate[0] = andGates[0].output();
	//		orGate[1] = andGates[1].output();
	//		orGate.process();

	//		SET_PIN(flipFlop, D_FlipFlop::D, orGate.output());
	//		SET_PIN(flipFlop, D_FlipFlop::CLOCK, PIN_VAL((*this), CLK));
	//		flipFlop.process();

	//		andGates[0][0] = PIN_VAL(flipFlop, D_FlipFlop::Q);

	//		SET_PIN(triBuffer, TriStateBuffer::ENABLE, PIN_VAL(triBuffer, TriStateBuffer::ENABLE));
	//		SET_PIN(triBuffer, TriStateBuffer::IN, PIN_VAL(flipFlop, D_FlipFlop::Q));
	//		triBuffer.process();

	//		setOutput(0, triBuffer.output());
	//	}

	//public:
	//	std::array<AND_Gate, 2> andGates;
	//	D_FlipFlop flipFlop;
	//	NOT_Gate notGate;
	//	OR_Gate orGate;
	//	TriStateBuffer triBuffer;
	//};
}