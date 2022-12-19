#pragma once
#include <array>

namespace dat
{
	template<size_t InputAmount, size_t OutputAmount>
	class Component
	{
	public:
		Component()
		{
			for (size_t i = 0; i < InputAmount; i++)
				m_Inputs[i] = false;

			for (size_t i = 0; i < OutputAmount; i++)
				m_Outputs[i] = false;
		}

		virtual ~Component() = default;

	public:
		bool operator[](size_t pinIndex) const
		{
			return m_Inputs[pinIndex];
		}

		bool& operator[](size_t pinIndex)
		{
			return m_Inputs[pinIndex];
		}

		void setOutput(size_t pinIndex = 0, bool value = 0)
		{
			m_Outputs[pinIndex] = value;
		}

		bool output(size_t pinIndex = 0) const
		{
			return m_Outputs[pinIndex];
		}

	public:
		virtual void process() { }

	private:
		std::array<bool, InputAmount> m_Inputs;
		std::array<bool, OutputAmount> m_Outputs;
	};
}