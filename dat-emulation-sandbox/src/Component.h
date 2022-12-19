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
				m_Inputs[i] = ZERO;

			for (size_t i = 0; i < OutputAmount; i++)
				m_Outputs[i] = ZERO;
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
}