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

	AstableClock clock(1000);
	EdgeDetector edgeDetector;

	Register registerCI;

	while (true)
	{
		clock.push();

		int a = getchNonBlock();

		if (a == 112) // P - Print
			std::cout << "OUT: " << registerCI.getNumber() << "\n";

		if (a == 101) // E - Switch ENABLE
		{
			registerCI.setEnable(!registerCI.getPin(Register::ENABLE));

			if (registerCI.getPin(Register::ENABLE))
				std::cout << "ENABLED ON\n";
			else
				std::cout << "ENABLED OFF\n";
		}

		if (a == 108) // L - LOAD
		{
			registerCI.setLoad(!registerCI.getPin(Register::LOAD));

			if (registerCI.getPin(Register::LOAD))
				std::cout << "LOAD ON\n";
			else
				std::cout << "LOAD OFF\n";
		}

		if (a == 49) // 1 - Set Number
		{
			int number;
			std::cout << "> ";
			std::cin >> number;
			registerCI.setNumber(number);
		}

		registerCI.setClock(clock.output());

		edgeDetector.detectPositive(clock.output(), [&]() {
			registerCI.process();
		});
	}
}
