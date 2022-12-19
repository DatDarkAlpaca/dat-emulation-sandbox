#pragma once
#include <chrono>

namespace dat
{
	class Clock
	{
	public:
		virtual ~Clock() = default;

	public:
		virtual void reset() = 0;

		virtual void push() = 0;

	public:
		bool output() const { return m_Output; }

	protected:
		bool m_Output = false;
	};

	class AstableClock : public Clock
	{
	public:
		AstableClock(double frequency)
			: m_Frequency(frequency)
		{
			reset();
		}

		AstableClock() = default;

	public:
		void setFrequency(double frequency) { m_Frequency = frequency; }

	public:
		void reset() override
		{
			m_Start = std::chrono::high_resolution_clock::now();
		}

		void push() override
		{
			std::chrono::time_point<std::chrono::high_resolution_clock> endTime;
			endTime = std::chrono::high_resolution_clock::now();

			double elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_Start).count();

			if (elapsed >= m_Frequency)
			{
				reset();
				m_Output = !m_Output;
			}
		}

	private:
		std::chrono::high_resolution_clock::time_point m_Start;
		double m_Frequency = 0;
	};

	class MonostableClock : public Clock
	{
	public:
		void reset() override
		{
			m_Output = false;
		}

		void push() override
		{
			m_Output = true;
		}
	};

	class BistableClock : public Clock
	{
	public:
		void reset() override
		{
			m_Output = false;
		}

		void push() override
		{
			m_Output = !m_Output;
		}
	};	
}