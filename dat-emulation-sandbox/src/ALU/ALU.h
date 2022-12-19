#pragma once
#include "ALU_1bit.h"
#include <iostream>

namespace dat
{
	class ALU : public Component<19, 9>
	{
	public:
		ALU()
		{
			for (auto& alu : alus)
				alu.setDecoder(&decoder);
		}

	public:
		State getF0() const { return (*this)[16 + 0]; }

		void setF0(State value) { (*this)[16 + 0] = value; }
		
		State getF1() const { return (*this)[16 + 1];}

		void setF1(State value) { (*this)[16 + 1] = value; }

		State getCarryIn() { return (*this)[16 + 2]; }

		void setCarryIn(State value) { (*this)[16 + 2] = value; }

	public:
		State getCarryOut() { return output(8); }

		void setCarryOut(State value) { return setOutput(8, value); }

	public:
		void setBitA(size_t index, State value)
		{
			if (index >= 8)
				throw "Invalid ALU A bit.";

			(*this)[index] = value;
		}

		void setBitB(size_t index, State value)
		{
			if (index >= 8)
				throw "Invalid ALU B bit.";

			(*this)[index + 8] = value;
		}

		State getBitA(size_t index) const
		{
			if (index >= 8)
				throw "Invalid ALU A bit.";

			return (*this)[index];
		}

		State getBitB(size_t index) const
		{
			if (index >= 8)
				throw "Invalid ALU B bit.";

			return (*this)[index + 8];
		}

	public:
		void process() override
		{
			for (size_t i = 0; i < alus.size(); ++i)
			{
				alus[i].setF0(getF0());
				alus[i].setF1(getF1());

				alus[i].setA(getBitA(i));
				alus[i].setB(getBitB(i));

				if(i > 0)
					alus[i].setCarryIn(alus[i - 1].getCarryOut());
				else
					alus[i].setCarryIn(getCarryIn());

				alus[i].process();

				setOutput(i, alus[i].getOutput());
			}				

			setCarryOut(alus.back().getCarryOut());
		}

	public:
		void setNumericA(uint8_t number)
		{
			for (size_t i = 0; i < 8; ++i)
			{
				int bit = ((number & (1 << i)) >> i);
				setBitA(i, fromBool(bit));
			}
		}

		void setNumericB(uint8_t number)
		{
			for (size_t i = 0; i < 8; ++i)
			{
				int bit = ((number & (1 << i)) >> i);
				setBitB(i, fromBool(bit));
			}
		}

		uint8_t getNumeric() const
		{
			uint8_t result = 0;
			for (size_t i = 0; i < alus.size(); ++i)
				result += output(i)* pow(2, i);

			return result;
		}

	public:
		Decoder2_to_4 decoder;
		std::array<ALU_1bit, 8> alus;
	};
}