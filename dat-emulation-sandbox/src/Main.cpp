#include <iostream>
#include <conio.h>
#include "Clock.h"
#include "flip_flops/JK_FlipFlop.h"
#include "flip_flops/D_FlipFlop.h"
#include "latches/SR_E_Latch.h"
#include "register/Register.h"

int getchNonBlock()
{
	if (_kbhit())
		return _getch();
	return 0;
}

void print(dat::JK_FlipFlop jk)
{
	using namespace dat;

	std::cout << "J: " << getString(jk[JK_FlipFlop::J]) << '\n';
	std::cout << "K: " << getString(jk[JK_FlipFlop::K]) << '\n';
	std::cout << "clk: " << getString(jk[JK_FlipFlop::CLOCK]) << '\n';
	std::cout << "Q | Q_INV: " << getString(jk[JK_FlipFlop::Q]) << " | ";
	std::cout << getString(jk[JK_FlipFlop::Q_INV]) << '\n';
	std::cout << '\n';
}

int main()
{
	using namespace dat;

	SR_Latch latch;
	std::cout << getString(latch.getPin(SR_Latch::Q)) << ' ' << getString(latch.getPin(SR_Latch::Q_INV)) << '\n';

	latch[SR_Latch::R] = ON;
	latch[SR_Latch::S] = ON;
	latch.process();
	std::cout << getString(latch.getPin(SR_Latch::Q)) << ' ' << getString(latch.getPin(SR_Latch::Q_INV)) << '\n';
	
	latch[SR_Latch::R] = OFF;
	latch[SR_Latch::S] = ON;
	latch.process();
	std::cout << getString(latch.getPin(SR_Latch::Q)) << ' ' << getString(latch.getPin(SR_Latch::Q_INV)) << '\n';

	latch[SR_Latch::R] = ON;
	latch[SR_Latch::S] = OFF;
	latch.process();
	std::cout << getString(latch.getPin(SR_Latch::Q)) << ' ' << getString(latch.getPin(SR_Latch::Q_INV)) << '\n';
}

int _main()
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
			registerCI.setNumber((uint8_t)number);
		}

		registerCI.setClock(clock.output());

		edgeDetector.detectPositive(clock.output(), [&]() {
			registerCI.process();
		});
	}
}
