#pragma once
#include "State.h"
#include "Component.h"

namespace dat
{
	class Buffer : public Component<1, 1>
	{
	public:
		void setInput(State value) { (*this)[0] = value; }

		State getInput() const { return (*this)[0]; }

	public:
		void process() override
		{
			setOutput(0, getInput());
		}
	};
}