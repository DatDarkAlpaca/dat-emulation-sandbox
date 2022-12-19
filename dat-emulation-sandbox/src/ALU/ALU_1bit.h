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
		void setA(bool value) { (*this)[0] = value; }

		void setB(bool value) { (*this)[1] = value; }

		void setCarryIn(bool value) { (*this)[2] = value; }

		void setF0(bool value) { (*this)[3] = value; }

		void setF1(bool value) { (*this)[4] = value; }

	public:
		bool getA() const { return (*this)[0]; }

		bool getB() const { return (*this)[1]; }

		bool getCarryIn() const { return (*this)[2]; }

		bool getF0() const { return (*this)[3]; }

		bool getF1() const { return (*this)[4]; }

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
			bool I0 = logicUnit.getNotOutput();
			bool I1 = decoder->output(0);
			bool I2 = logicUnit.getOrOutput();
			bool I3 = decoder->output(1);
			bool I4 = logicUnit.getAndOutput();
			bool I5 = decoder->output(2);
			bool I6 = decoder->output(3);
			bool I7 = fullAdder.getSum();

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
		bool getOutput() const { return output(); }

		bool getCarryOut() const { return output(1); }

	private:
		std::array<AND_Gate, 4> andGates;
		XOR_Gate_4IN outGate;

	private:
		Decoder2_to_4* decoder = nullptr;
		Full_Adder fullAdder;
		ALU_LogicUnit logicUnit;
	};
}