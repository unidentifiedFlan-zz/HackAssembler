#include "stdafx.h"
#include "Code.h"


code::code(std::string file) {

	file.append(".hack");
	hackFile.open(file, std::fstream::out);

}


void code::A_Code(int currSymbol) {

	for (int i = 0; i<16; i++)
		binCommand[i] = '0';

	unsigned int MLoc = (unsigned int)currSymbol;

	convertToBinary(binCommand, MLoc);

}

void code::dest(std::string currDest, std::string &file) {

	if (currDest == "null") {
		for (int i = 10; i < 13; i++)
			binCommand[i] = '0';
	}

	if (currDest[0] == 'A')
		binCommand[10] = '1';
	else
		binCommand[10] = '0';

	if (currDest.find("M") != std::string::npos)
		binCommand[12] = '1';
	else
		binCommand[12] = '0';

	if (currDest.find("D") != std::string::npos)
		binCommand[11] = '1';
	else
		binCommand[11] = '0';
}

void code::comp(std::string currComp, std::string &file) {

	for (int i = 0; i<3; i++)
		binCommand[i] = '1';

	if (currComp.find('M') != std::string::npos)
		binCommand[3] = '1';
	else
		binCommand[3] = '0';

	std::string c;
	if (currComp == "0")
		c = "101010";
	else if (currComp == "1")
		c = "111111";
	else if (currComp == "-1")
		c = "111010";
	else if (currComp == "D")
		c = "001100";
	else if (currComp == "A" || currComp == "M")
		c = "110000";
	else if (currComp == "!D")
		c = "001101";
	else if (currComp == "!A" || currComp == "!M")
		c = "110001";
	else if (currComp == "-D")
		c = "001111";
	else if (currComp == "-A" || currComp == "-M")
		c = "110011";
	else if (currComp == "D+1")
		c = "011111";
	else if (currComp == "A+1" || currComp == "M+1")
		c = "110111";
	else if (currComp == "D-1")
		c = "001110";
	else if (currComp == "A-1" || currComp == "M-1")
		c = "110010";
	else if (currComp == "D+A" || currComp == "D+M")
		c = "000010";
	else if (currComp == "D-A" || currComp == "D-M")
		c = "010011";
	else if (currComp == "A-D" || currComp == "M-D")
		c = "000111";
	else if (currComp == "D&A" || currComp == "D&M")
		c = "000000";
	else if (currComp == "D|A" || currComp == "D|M")
		c = "010101";

	for (int i = 4; i < 10; i++)
		binCommand[i] = c[i - 4];

}

void code::jump(std::string currJump, std::string &file) {

	for (int i = 0; i < 3; i++) {
		binCommand[i + 13] = '0';
	}

	if (currJump.find("JGT") != std::string::npos) {
		binCommand[13] = '0';
		binCommand[14] = '0';
		binCommand[15] = '1';
	}


	else if (currJump.find("JEQ") != std::string::npos) {
		binCommand[13] = '0';
		binCommand[14] = '1';
		binCommand[15] = '0';
	}

	else if (currJump.find("JGE") != std::string::npos) {
		binCommand[13] = '0';
		binCommand[14] = '1';
		binCommand[15] = '1';
	}

	else if (currJump.find("JLT") != std::string::npos) {
		binCommand[13] = '1';
		binCommand[14] = '0';
		binCommand[15] = '0';
	}

	else if (currJump.find("JNE") != std::string::npos) {
		binCommand[13] = '1';
		binCommand[14] = '0';
		binCommand[15] = '1';
	}

	else if (currJump.find("JLE") != std::string::npos) {
		binCommand[13] = '1';
		binCommand[14] = '1';
		binCommand[15] = '0';
	}

	else if (currJump.find("JMP") != std::string::npos) {
		binCommand[13] = '1';
		binCommand[14] = '1';
		binCommand[15] = '1';
	}

}

void code::writeHack() {

	int i = 0;
	while (i < 16) {

		hackFile << binCommand[i];
		std::cout << binCommand[i];
		i++;
	}
	std::cout << "\n";
	hackFile << "\n";

}

void code::endStream() {

	hackFile.close();
}
