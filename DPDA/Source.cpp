#include "DPDA.h"
#include <iostream>

int main() {
	DPDA automata;

	std::string input("110000111000000");
	if (automata.conformityCheck(input) == true)
	{
		std::cout << "TRUE!" << std::endl;
	}
	else
	{
		std::cout << "FALSE!" << std::endl;
	}

	std::cin.get();
	return 0;
}
