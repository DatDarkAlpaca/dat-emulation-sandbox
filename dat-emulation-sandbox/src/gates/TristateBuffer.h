#pragma once
#include "Component.h"

namespace dat
{
	class TriStateBuffer : public Component<2, 1>
	{
	public:
		void setEnable(State value) { (*this)[0] = value; }

		State getEnable() const { return (*this)[0]; }

		void setInput(State value) { (*this)[1] = value; }

		State getInput() const { return (*this)[1]; }

	public:
		void process() override
		{
			if (!getEnable())
				setOutput(0, ZERO);
			else
				setOutput(0, getInput());
		}
	};
}