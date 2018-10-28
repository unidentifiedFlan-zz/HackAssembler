#include "stdafx.h"
#include "HackAssembler.h"

int main() {

	std::string file;
	std::cout << "Please input a file to assemble:" << std::endl;
	std::cin >> file;

	HackAssembler HackAssembler(file);

	return 0;
}