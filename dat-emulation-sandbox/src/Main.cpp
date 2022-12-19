#include <iostream>
#include <conio.h>
#include "Clock.h"
#include "register/Register.h"

int getchNonBlock()
{
	if (_kbhit())
		return _getch();
	return 0;
}

int main()
{
	using namespace dat;
	
	AstableClock clock(1 / 1'000'000);
	EdgeDetector edgeDetector;
	
	Register_1bit registerCI;

	while (true)
	{
		clock.push();
		
		int a = getchNonBlock();

		if (a == 112) // P
		{
			std::cout << registerCI.output(0) << "\n";
		}
		if (a == 122) // Z
		{
			registerCI.setEnable(!registerCI.getEnable());

			if(registerCI.getEnable())
				std::cout << "ENABLED ON\n";
			else
				std::cout << "ENABLED OFF\n";
		}

		if (a == 108) // L
		{
			registerCI.setLoad(!registerCI.getLoad());

			if(!registerCI.getLoad())
				std::cout << "LOAD OFF\n";
			else
				std::cout << "LOAD ON\n";
		}

		if (a == 119) // W
		{
			std::cout << "D1 ON\n";
			registerCI.setD1(ON);
		}

		else if (a == 115) // S
		{
			std::cout << "D1 OFF\n";
			registerCI.setD1(OFF);
		}

		registerCI.setClock(clock.output());

		edgeDetector.detectPositive(clock.output(), [&]() {
			registerCI.process();
		});
	}

	return 0;
}
