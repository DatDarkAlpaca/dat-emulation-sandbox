#pragma once
#include <array>
#include "Component.h"
#include "gates/Gates.h"
#include "components/Decoder2_to_4.h"
#include "ALU_LogicUnit.h"
#include "components/Full_Adder.h"

namespace dat
{
	class ALU_1bit : public Component<7>
	{
	public:
		static inline constexpr unsigned A = 0;

		static inline constexpr unsigned B = 1;

		static inline constexpr unsigned CARRY_IN = 2;

		static inline constexpr unsigned F0 = 3;

		static inline constexpr unsigned F1 = 4;

		static inline constexpr unsigned OUT = 5;

		static inline constexpr unsigned CARRY_OUT = 6;

	public:
		ALU_1bit(Decoder2_to_4* decoder)
			: decoder(decoder)
		{
		}

		ALU_1bit() = default;

	public:
		void setDecoder(Decoder2_to_4* decoder)
		{
			this->decoder = decoder;
		}

	public:
		void process() override
		{
			// Decoder Input:
			decoder->setPin(Decoder2_to_4::F0, getPin(F0));
			decoder->setPin(Decoder2_to_4::F1, getPin(F1));
			decoder->process();

			// LU Input:
			logicUnit.setPin(A, getPin(A));
			logicUnit.setPin(B, getPin(B));
			logicUnit.process();

			// FA Input:
			fullAdder.setPin(Full_Adder::A, getPin(A));
			fullAdder.setPin(Full_Adder::B, getPin(B));
			fullAdder.setPin(Full_Adder::CARRY_IN, getPin(CARRY_IN));
			fullAdder.process();

			setPin(CARRY_OUT, fullAdder.getPin(Full_Adder::CARRY_OUT));

			// Inputs:
			State I0 = logicUnit[ALU_LogicUnit::NOT_OUT];
			State I1 = (*decoder)[Decoder2_to_4::OUT_0];
			State I2 = logicUnit[ALU_LogicUnit::OR_OUT];
			State I3 = (*decoder)[Decoder2_to_4::OUT_1];
			State I4 = logicUnit[ALU_LogicUnit::AND_OUT];
			State I5 = (*decoder)[Decoder2_to_4::OUT_2];
			State I6 = (*decoder)[Decoder2_to_4::OUT_3];
			State I7 = fullAdder.getPin(Full_Adder::SUM);

			// Aliases:
			auto& A = andGates;

			// Processing AND gates:
			A[0][0] = I0;
			A[0][1] = I1;

			A[1][0] = I2;
			A[1][1] = I3;

			A[2][0] = I4;
			A[2][1] = I5;

			A[3][0] = I6;
			A[3][1] = I7;

			for (auto& andGate : andGates)
				andGate.process();

			// Xor Gate Output:
			outGate[0] = A[0].getPin(AND_Gate::OUT);
			outGate[1] = A[1].getPin(AND_Gate::OUT);
			outGate[2] = A[2].getPin(AND_Gate::OUT);
			outGate[3] = A[3].getPin(AND_Gate::OUT);

			outGate.process();
			setPin(OUT, outGate.getPin(XOR_Gate_4IN::OUT));
		}

	private:
		std::array<AND_Gate, 4> andGates;
		XOR_Gate_4IN outGate;

	private:
		Decoder2_to_4* decoder = nullptr;
		Full_Adder fullAdder;
		ALU_LogicUnit logicUnit;
	};
}