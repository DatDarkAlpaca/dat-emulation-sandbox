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

void registerTest()
{
	//using namespace dat;

	//AstableClock clock(1 / 1'000'000);
	//EdgeDetector edgeDetector;

	//Register_1bit registerCI;

	//while (true)
	//{
	//	clock.push();

	//	int a = getchNonBlock();

	//	if (a == 112) // P
	//	{
	//		std::cout << registerCI.output(0) << "\n";
	//	}
	//	if (a == 122) // Z
	//	{
	//		SET_PIN(registerCI, Register_1bit::ENABLE, !PIN_VAL(registerCI, Register_1bit::ENABLE));

	//		if (PIN_VAL(registerCI, Register_1bit::ENABLE))
	//			std::cout << "ENABLED ON\n";
	//		else
	//			std::cout << "ENABLED OFF\n";
	//	}

	//	if (a == 108) // L
	//	{
	//		SET_PIN(registerCI, Register_1bit::LOAD, !PIN_VAL(registerCI, Register_1bit::LOAD));

	//		if (!PIN_VAL(registerCI, Register_1bit::LOAD))
	//			std::cout << "LOAD OFF\n";
	//		else
	//			std::cout << "LOAD ON\n";
	//	}

	//	if (a == 119) // W
	//	{
	//		std::cout << "D1 ON\n";
	//		SET_PIN(registerCI, Register_1bit::D1, ON);
	//	}

	//	else if (a == 115) // S
	//	{
	//		std::cout << "D1 OFF\n";
	//		SET_PIN(registerCI, Register_1bit::D1, OFF);
	//	}

	//	SET_PIN(registerCI, Register_1bit::CLK, clock.output());

	//	edgeDetector.detectPositive(clock.output(), [&]() {
	//		registerCI.process();
	//	});
	//}
}

int main()
{
	using namespace dat;
	AND_Gate gate;

	gate.setPin(AND_Gate::IN_0, ON);

	//std::cout << PIN_STR(gate, AND_Gate::IN_0);
}
