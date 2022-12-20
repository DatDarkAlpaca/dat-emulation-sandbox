#pragma once
#include <array>
#include "State.h"

namespace dat
{
	template<size_t InputAmount, size_t OutputAmount>
	class Component
	{
	public:
		Component()
		{
			for (size_t i = 0; i < InputAmount; i++)
				m_Inputs[i] = OFF;

			for (size_t i = 0; i < OutputAmount; i++)
				m_Outputs[i] = OFF;
		}

		virtual ~Component() = default;

	public:
		State operator[](size_t pinIndex) const
		{
			return m_Inputs[pinIndex];
		}

		State& operator[](size_t pinIndex)
		{
			return m_Inputs[pinIndex];
		}

		void setOutput(size_t pinIndex = 0, State value = 0)
		{
			m_Outputs[pinIndex] = value;
		}

		State output(size_t pinIndex = 0) const
		{
			return m_Outputs[pinIndex];
		}

	public:
		virtual void process() { }

	private:
		std::array<State, InputAmount> m_Inputs;
		std::array<State, OutputAmount> m_Outputs;
	};

	#define SET_PIN(DEVICE, PIN, VALUE) \
	DEVICE[PIN] = VALUE

	#define PIN_OFF(DEVICE, PIN)	\
	DEVICE[PIN] = dat::State::OFF_STATE

	#define PIN_ON(DEVICE, PIN)	\
	DEVICE[PIN] = dat::State::ON_STATE

	#define PIN_VAL(DEVICE, PIN)	\
	DEVICE[PIN]

	#define PIN_STR(DEVICE, PIN)	\
	getString(DEVICE[PIN])
}