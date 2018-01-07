#include "DPDA.h"
#include <iostream>

int main() {
	DPDA* automata = DPDA::getInstance();

	const std::string input("110000111000000");
	if (automata->conformityCheck(input) == true)
	{
		std::cout << "TRUE!" << std::endl;
	}
	else
	{
		std::cout << "FALSE!" << std::endl;
	}

	system("pause");
	return 0;
}
