#include "ALU/ALU.h"
#include <iostream>

int main()
{
	dat::ALU alu;
	alu.setF0(1); alu.setF1(1);

	alu.setNumericA(0);
	alu.setNumericB(0);
	alu.setCarryIn(0);

	alu.process();

	return 0;
}