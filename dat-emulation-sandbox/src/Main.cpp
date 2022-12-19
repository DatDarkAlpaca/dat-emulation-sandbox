#include <iostream>
#include <conio.h>
#include "Clock.h"
#include "gates/AND_Gate.h"

#include "components/Register_1bit.h"
#include "flip_flops/D_FlipFlop.h"

int getchNonBlock()
{
	if (_kbhit())
		return _getch();
	return 0;
}

int main()
{
	using namespace dat;
	
	AstableClock clock(100);
	EdgeDetector edgeDetector;
	
	Register_1bit register1bit;

	while (true)
	{
		clock.push();
		
		int a = getchNonBlock();
		if (a == 119)
		{
			register1bit.setEnable(ON);
			register1bit.setLoad(ON);
			register1bit.setD1(ON);
		}
		else if (a == 115)
		{
			register1bit.setEnable(OFF);
			register1bit.setLoad(OFF);
			register1bit.setD1(OFF);
		}

		register1bit.setClock(clock.output());

		edgeDetector.detectPositive(clock.output(), [&]() {
			register1bit.process();
			std::cout << register1bit.output() << "\n";
		});
	}

	return 0;
}
