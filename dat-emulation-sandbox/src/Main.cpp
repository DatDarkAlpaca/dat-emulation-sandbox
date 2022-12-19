#include "ALU/ALU.h"
#include <iostream>

int main()
{
	// ALU:
	dat::ALU alu;
	alu.setF0(1); alu.setF1(1);

	alu.setNumericA(255);
	alu.setNumericB(255);
	alu.setCarryIn(1);

	alu.process();

	alu.getNumeric();

	return 0;
}