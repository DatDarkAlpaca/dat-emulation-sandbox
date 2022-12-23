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

	AstableClock clock(200);
	EdgeDetector edge;
	SR_E_Latch gate;

	gate[SR_E_Latch::R] = OFF;
	gate[SR_E_Latch::S] = OFF;
	gate[SR_E_Latch::E] = OFF;

	while (true)
	{
		clock.push();

		int a = getchNonBlock();

		 if (a) std::cout << a << '\n';

		if (a == 99) // C - Clear
		{
			gate[SR_E_Latch::R] = OFF;
			gate[SR_E_Latch::S] = OFF;
		}

		if (a == 118) // V - ON
		{
			gate[SR_E_Latch::R] = ON;
			gate[SR_E_Latch::S] = ON;
		}

		if (a == 101) // E - Switch ENABLE
		{
			gate[SR_E_Latch::R] = gate[SR_E_Latch::S];
			gate[SR_E_Latch::S] = !gate[SR_E_Latch::R];

			std::cout << "S: " << getString(gate[SR_E_Latch::S]) << ' ' << " | R: " << getString(gate[SR_E_Latch::R]) << '\n';
		}
	
		gate[SR_E_Latch::E] = clock.output();

		edge.detectPositive(clock.output(), [&]() {
			gate.process();
			std::cout << getString(gate[SR_E_Latch::Q]) << '\n';
		});
	}
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
