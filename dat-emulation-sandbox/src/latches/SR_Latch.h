#pragma once
#include <array>
#include "Component.h"
#include "gates/Gates.h"

namespace dat
{
	class SR_Latch : public Component<2, 2>
	{
	public:
		bool getR() const { return (*this)[0]; }
		
		void setR(bool value) { (*this)[0] = value; }

		bool getS() const { return (*this)[1]; }

		void setS(bool value) { (*this)[1] = value; }

	public:
		bool getQ() const { return output(0); }

		bool getQ_INV() const { return output(1); }

	private:
		void setQ(bool value) { setOutput(0, value); }

		void setQ_INV(bool value) { setOutput(1, value); }

	public:
		void process() override
		{
			// Q initially open:
			norGates[0][0] = getR();
			norGates[0].process();

			norGates[1][0] = norGates[0].output();
			norGates[1][1] = getS();
			norGates[1].process();

			norGates[0][1] = norGates[1].output();
			norGates[0].process();

			setQ(norGates[0].output());
			setQ_INV(norGates[1].output());
		}

	private:
		std::array<NOR_Gate, 2> norGates;
	};
}