#pragma once
#include <array>
#include "Component.h"
#include "gates/TristateBuffer.h"
#include "flip_flops/D_FlipFlop.h"

namespace dat 
{
	class Register_1bit : public Component<5>
	{
	public:
		static inline constexpr unsigned LOAD = 0;

		static inline constexpr unsigned D = 1;

		static inline constexpr unsigned CLK = 2;

		static inline constexpr unsigned ENABLE = 3;

		static inline constexpr unsigned OUT = 4;

	public:
		Register_1bit()
		{
			setPin(OUT, ZERO);
			andGates[0][0] = ON;
		}

	public:
		void process() override
		{
			using namespace dat;
		
			notGate[0] = getPin(LOAD);
			notGate.process();
		
			// andGates[0][0] = default;
			andGates[0][1] = notGate.getPin(NOT_Gate::OUT);
			andGates[0].process();
		
			andGates[1][0] = getPin(LOAD);
			andGates[1][1] = getPin(D);
			andGates[1].process();
		
			orGate[0] = andGates[0].getPin(AND_Gate::OUT);
			orGate[1] = andGates[1].getPin(AND_Gate::OUT);
			orGate.process();
		
			flipFlop.setPin(D_FlipFlop::D, orGate.getPin(OR_Gate::OUT));
			flipFlop.setPin(D_FlipFlop::CLOCK, getPin(CLK));
			flipFlop.process();
		
			andGates[0][0] = flipFlop.getPin(D_FlipFlop::Q);

			triBuffer.setPin(TristateBuffer::ENABLE, getPin(ENABLE));
			triBuffer.setPin(TristateBuffer::IN, flipFlop.getPin(D_FlipFlop::Q));

			triBuffer.process();
		
			setPin(OUT, triBuffer.getPin(TristateBuffer::OUT));
		}

	public:
		std::array<AND_Gate, 2> andGates;
		TristateBuffer triBuffer;
		D_FlipFlop flipFlop;
		NOT_Gate notGate;
		OR_Gate orGate;
	};
}