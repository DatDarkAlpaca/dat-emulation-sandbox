#pragma once
#include <chrono>
#include <functional>
#include "State.h"

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
		State output() const { return m_Output; }

	protected:
		State m_Output = State::OFF_STATE;
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
			m_Output = OFF;
		}

		void push() override
		{
			m_Output = ON;
		}
	};

	class BistableClock : public Clock
	{
	public:
		void reset() override
		{
			m_Output = OFF;
		}

		void push() override
		{
			m_Output = !m_Output;
		}
	};

	// Todo: move both the clock and the edge detector
	class EdgeDetector
	{
	public:
		void update(State clockOutput)
		{
			m_OldClock = clockOutput;
		}

		void detectPositive(State clockOutput, std::function<void(void)> function)
		{
			if (!m_OldClock && clockOutput)
				function();			
		}

		void detectNegative(State clockOutput, std::function<void(void)> function)
		{
			if (m_OldClock && !clockOutput)
				function();
		}

	public:
		State m_OldClock = OFF;
	};

}