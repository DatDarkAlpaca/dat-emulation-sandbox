#pragma once
#include <array>
#include "State.h"

namespace dat
{
	template<size_t PinAmount>
	class Component
	{
	public:
		Component()
		{
			for (size_t i = 0; i < PinAmount; i++)
				m_Pins[i] = OFF;
		}

		virtual ~Component() = default;

	public:
		State operator[](size_t pin) const
		{
			return m_Pins[pin];
		}

		State& operator[](size_t pin)
		{
			return m_Pins[pin];
		}

	public:
		void setPin(size_t pin, State value)
		{
			m_Pins[pin] = value;
		}

		State getPin(size_t pin) const
		{
			return (*this)[pin];
		}

		void pinOn(size_t pin)
		{
			m_Pins[pin] = ON;
		}

		void pinOff(size_t pin)
		{
			m_Pins[pin] = OFF;
		}

		const char* pinStr(size_t pin) const
		{
			return getString(getPin(pin));
		}

	public:
		virtual void process() { }

	public:
		std::array<State, PinAmount> m_Pins;
	};
}