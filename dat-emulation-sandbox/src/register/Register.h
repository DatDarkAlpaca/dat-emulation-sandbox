#pragma once
#include <array>
#include <numeric>
#include "Component.h"
#include "Register_1bit.h"

#define REGISTER_BIT_SIZE 8

namespace dat
{
	class Register : public Component<3 + 2 * REGISTER_BIT_SIZE>
	{
	public:
		static inline constexpr unsigned DATA[REGISTER_BIT_SIZE] = {
			0, 1, 2, 3, 4, 5, 6, 7
		};

		static inline constexpr unsigned OUT[REGISTER_BIT_SIZE] = {
			8, 9, 10, 11, 12, 13, 14, 15
		};

		static inline constexpr unsigned LOAD = 16;

		static inline constexpr unsigned CLK = 17;

		static inline constexpr unsigned ENABLE = 18;

	public:
		Register()
		{
			for (size_t i = 0; i < 8; ++i)
			{
				pinOff(DATA[i]);
				setPin(OUT[i], ZERO);
			}
		}

	public:
		void setClock(State clockOutput)
		{
			setPin(CLK, clockOutput);
			
			for(size_t i = 0; i < REGISTER_BIT_SIZE; ++i)
				registers[i].setPin(Register_1bit::CLK, getPin(CLK));
		}

		void setEnable(State clockOutput)
		{
			setPin(ENABLE, clockOutput);

			for (size_t i = 0; i < REGISTER_BIT_SIZE; ++i)
				registers[i].setPin(Register_1bit::ENABLE, getPin(ENABLE));
		}

		void setLoad(State clockOutput)
		{
			setPin(LOAD, clockOutput);

			for (size_t i = 0; i < REGISTER_BIT_SIZE; ++i)
				registers[i].setPin(Register_1bit::LOAD, getPin(LOAD));
		}

	public:
		void setNumber(int number)
		{
			for (int i = 0; i < 8; ++i)
			{
				int bit = (number & (1 << i)) >> i;	
				setPin(DATA[i], bit ? State::ON_STATE : State::OFF_STATE);
				registers[i].setPin(Register_1bit::D, getPin(DATA[i]));
			}
		}

		int getNumber() const
		{
			for (size_t i = 0; i < 8; ++i)
			{
				if (getPin(OUT[i]) == ZERO)
					return -1;
			}

			int result = 0;
			for (int i = 0; i < REGISTER_BIT_SIZE; ++i)
			{
				int pin = getPin(OUT[i]) == OFF ? 0 : 1;
				result += pow(2, i) * pin;
			}
			
			return result;
		}

	public:
		void process() override
		{
			if (!getPin(ENABLE))
			{
				for (size_t i = 0; i < REGISTER_BIT_SIZE; ++i)
					setPin(OUT[i], ZERO);
				return;
			}

			for (size_t i = 0; i < REGISTER_BIT_SIZE; ++i)
			{
				registers[i].process();
				setPin(OUT[i], registers[i].getPin(Register_1bit::OUT));
			}
		}

	public:
		std::array<Register_1bit, REGISTER_BIT_SIZE> registers;
	};
}