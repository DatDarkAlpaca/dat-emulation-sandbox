#pragma once
#include <array>
#include "Component.h"
#include "Register_1bit.h"

#define REGISTER_BIT_SIZE 8

namespace dat
{
	class Register : public Component<REGISTER_BIT_SIZE + 3, REGISTER_BIT_SIZE>
	{
	public:
		Register()
		{
			setLoad(OFF);
			setEnable(OFF);
		}

	public:
		State getData(size_t index) const 
		{ 
			if (index > REGISTER_BIT_SIZE - 1)
				throw "Invalid register data pin";

			return (*this)[index]; 
		}

		void setData(size_t index, State value) 
		{
			if (index > REGISTER_BIT_SIZE - 1)
				throw "Invalid register data pin";

			(*this)[index] = value; 
		}

		State getLoad() const { return (*this)[REGISTER_BIT_SIZE]; }

		void setLoad(State value) { (*this)[REGISTER_BIT_SIZE] = value; }

		State getClock() const { return (*this)[REGISTER_BIT_SIZE + 1]; }

		void setClock(State value) { (*this)[REGISTER_BIT_SIZE + 1] = value; }

		State getEnable() const { return (*this)[REGISTER_BIT_SIZE + 2]; }

		void setEnable(State value) { (*this)[REGISTER_BIT_SIZE + 2] = value; }

	public:
		void process() override
		{
			if (!getEnable())
			{
				for (size_t i = 0; i < REGISTER_BIT_SIZE; ++i)
					setOutput(i, ZERO);
			}

			for (size_t i = 0; i < REGISTER_BIT_SIZE; ++i)
			{
				registers[i].setClock(getClock());
				registers[i].setLoad(getLoad());
				registers[i].setEnable(getEnable());
				registers[i].setD1(getData(i));
				registers[i].process();

				setOutput(0, registers[0].output());
			}
		}

	public:
		std::array<Register_1bit, REGISTER_BIT_SIZE> registers;
	};
}