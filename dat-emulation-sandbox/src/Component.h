#pragma once
#if _DEBUG
	#include <cstdio>
#endif

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
#if _DEBUG
		virtual void display(const char* gateName) const
		{
			for (int i = 0; i < m_Inputs.size(); ++i)
				printf("%s [%d]i: %d\n", gateName, i, m_Inputs[i]);

			for (int i = 0; i < m_Outputs.size(); ++i)
				printf("%s [%d]o: %d\n", gateName, i, m_Outputs[i]);
		}
#endif

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