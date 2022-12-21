#pragma once

namespace dat
{
	enum State : int8_t
	{
		ZERO_STATE = -1,
		OFF_STATE  = false,
		ON_STATE   = true
	};

#define ZERO dat::State::ZERO_STATE
#define OFF dat::State::OFF_STATE
#define ON dat::State::ON_STATE

	inline const char* getString(State state)
	{
		switch (state)
		{
			case State::ZERO_STATE:
				return "ZERO";
			case State::OFF_STATE:
				return "OFF";
			case State::ON_STATE:
				return "ON";
			default:
				return "INVALID";
		}
	}

	inline State fromBool(bool value)
	{
		if (value)
			return ON;

		return OFF;
	}

	inline State operator&&(State lhs, State rhs)
	{
		if (lhs == ZERO && rhs == ZERO)
			return ZERO;

		if (lhs == ON && rhs == ON)
			return ON;

		if ((lhs == ON || rhs == ON) && (lhs == ZERO || rhs == ZERO))
			return ZERO;

		return OFF;
	}

	inline State operator||(State lhs, State rhs)
	{
		if (lhs == ZERO && rhs == ZERO)
			return ZERO;

		if (lhs == ON || rhs == ON)
			return ON;

		if (lhs == ZERO || rhs == ZERO)
			return ZERO;

		return OFF;
	}

	inline State operator^(State lhs, State rhs)
	{
		if (lhs == ZERO || rhs == ZERO)
			return ZERO;

		if (lhs == ON ^ rhs == ON)
			return ON;

		return OFF;
	}

	inline State operator!(State lhs)
	{
		if (lhs == ZERO)
			return ZERO;

		if (lhs == OFF)
			return ON;

		return OFF;
	}
}