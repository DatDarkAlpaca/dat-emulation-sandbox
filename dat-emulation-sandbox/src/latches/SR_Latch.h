#pragma once
#include <array>
#include "Component.h"
#include "gates/Gates.h"

namespace dat
{
	class SR_Latch : public Component<4>
	{
	public:
		static inline constexpr unsigned R = 0;

		static inline constexpr unsigned S = 1;

		static inline constexpr unsigned Q = 2;

		static inline constexpr unsigned Q_INV = 3;

	public:
		SR_Latch()
		{
			pinOn(Q);
		}

	public:
		void process() override
		{
			auto s = getPin(S);
			auto r = getPin(R);
			auto q = getPin(Q);
			auto q_ = getPin(Q_INV);

			if (!s && !r) { }

			if (s && q_)
			{
				pinOn(Q);
				pinOff(Q_INV);
			}

			if (r && q)
			{
				pinOn(Q_INV);
				pinOff(Q);
			}

			if (r && s)
			{
				invalidState = true;
				pinOff(Q);
				pinOff(Q_INV);
			}

			if (!r || !s && invalidState)
			{
				pinOn(Q);
				pinOff(Q_INV);
				invalidState = false;
			}
		}

	private:
		bool invalidState = false;
	};
}