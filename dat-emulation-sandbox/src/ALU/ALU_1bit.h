#pragma once
#include <array>
#include "Component.h"
#include "gates/Gates.h"
#include "components/Decoder2_to_4.h"
#include "ALU_LogicUnit.h"
#include "components/Full_Adder.h"

namespace dat
{
	class ALU_1bit : public Component<5, 2>
	{
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
		void setA(State value) { (*this)[0] = value; }

		void setB(State value) { (*this)[1] = value; }

		void setCarryIn(State value) { (*this)[2] = value; }

		void setF0(State value) { (*this)[3] = value; }

		void setF1(State value) { (*this)[4] = value; }

	public:
		State getA() const { return (*this)[0]; }

		State getB() const { return (*this)[1]; }

		State getCarryIn() const { return (*this)[2]; }

		State getF0() const { return (*this)[3]; }

		State getF1() const { return (*this)[4]; }

	public:
		void process() override
		{
			// Decoder Input:
			decoder->setF0(getF0());
			decoder->setF1(getF1());
			decoder->process();

			// LU Input:
			logicUnit.setA(getA());
			logicUnit.setB(getB());
			logicUnit.process();

			// FA Input:
			fullAdder.setA(getA());
			fullAdder.setB(getB());
			fullAdder.setCarryIn(getCarryIn());
			fullAdder.process();
			setOutput(1, fullAdder.getCarryOut());	// Carry Out

			// Inputs:
			State I0 = logicUnit.getNotOutput();
			State I1 = decoder->output(0);
			State I2 = logicUnit.getOrOutput();
			State I3 = decoder->output(1);
			State I4 = logicUnit.getAndOutput();
			State I5 = decoder->output(2);
			State I6 = decoder->output(3);
			State I7 = fullAdder.getSum();

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
			outGate[0] = A[0].output();
			outGate[1] = A[1].output();
			outGate[2] = A[2].output();
			outGate[3] = A[3].output();

			outGate.process();
			setOutput(0, outGate.output());			// Output
		}

	public:
		State getOutput() const { return output(); }

		State getCarryOut() const { return output(1); }

	private:
		std::array<AND_Gate, 4> andGates;
		XOR_Gate_4IN outGate;

	private:
		Decoder2_to_4* decoder = nullptr;
		Full_Adder fullAdder;
		ALU_LogicUnit logicUnit;
	};
}