#include "ALU/ALU_1bit.h"
#include <iostream>

int main()
{
	dat::Decoder2_to_4 decoder;
	dat::ALU_1bit alu(&decoder);
	alu.setF0(1); alu.setF1(0);

	alu.setA(1); alu.setB(1);
	alu.process();

	std::cout << alu.output() << '\n';

	return 0;
}