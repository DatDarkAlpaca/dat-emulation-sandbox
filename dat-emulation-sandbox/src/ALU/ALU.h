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
		bool getF0() const { return (*this)[16 + 0]; }

		void setF0(bool value) { (*this)[16 + 0] = value; }
		
		bool getF1() const { return (*this)[16 + 1];}

		void setF1(bool value) { (*this)[16 + 1] = value; }

		bool getCarryIn() { return (*this)[16 + 2]; }

		void setCarryIn(bool value) { (*this)[16 + 2] = value; }

	public:
		bool getCarryOut() { return output(8); }

		void setCarryOut(bool value) { return setOutput(8, value); }

	public:
		void setBitA(size_t index, bool value)
		{
			if (index >= 8)
				throw "Invalid ALU A bit.";

			(*this)[index] = value;
		}

		void setBitB(size_t index, bool value)
		{
			if (index >= 8)
				throw "Invalid ALU B bit.";

			(*this)[index + 8] = value;
		}

		bool getBitA(size_t index) const
		{
			if (index >= 8)
				throw "Invalid ALU A bit.";

			return (*this)[index];
		}

		bool getBitB(size_t index) const
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
				setBitA(i, ((number & (1 << i)) >> i));
		}

		void setNumericB(uint8_t number)
		{
			for (size_t i = 0; i < 8; ++i)
				setBitB(i, ((number & (1 << i)) >> i));
		}

		uint8_t getNumeric() const
		{
			for (size_t i = 0; i < alus.size(); ++i)
				std::cout << "O[" << i << "]: " << output(i) << '\n';

			std::cout << "C: " << output(8) << '\n';
			return 0;
		}

	public:
		Decoder2_to_4 decoder;
		std::array<ALU_1bit, 8> alus;
	};
}