#include "stdafx.h"
#include "Parser.h"


parser::parser(std::string file) {

	file.append(".asm");
	fileStream.open(file, std::fstream::in);

}

bool parser::hasMoreCommands() {

	fileStream >> std::ws;

	while (fileStream.peek() == '/' || fileStream.peek() == '\n') {

		fileStream.ignore(256, '\n');
		fileStream >> std::ws;

	}

	if (fileStream.eof())
		return false;

	return true;
}

void parser::advance() {

	currentCommand[0] = '\0';

	fileStream >> std::ws;
	fileStream.getline(currentCommand, 256);

	for (int i = 0; i < sizeof(currentCommand); i++) {

		if (currentCommand[i] == '\n' || currentCommand[i] == '\\' || currentCommand[i] == ' ')
			currentCommand[i] = '\0';

	}

	std::cout << currentCommand << std::endl;


}

std::string parser::commandType() {

	if (currentCommand[0] == '@')
		commType = "A_COMMAND";


	else if (currentCommand[0] == '(')
		commType = "L_COMMAND";


	else
		commType = "C_COMMAND";

	return commType;
}

std::string parser::symbol() {

	sym.clear();

	int i = 1;

	while (currentCommand[i] != '\0' && currentCommand[i] != ')') {

		sym.push_back(currentCommand[i]);
		i++;

	}

	return sym;
}

std::string parser::dest() {

	currentDest.clear();

	char* equalsPos;
	char* end = currentCommand + sizeof(currentCommand) / sizeof(currentCommand[0]);

	equalsPos = std::find(currentCommand, end, '=');

	if (equalsPos == end) {
		currentDest.push_back('\0');
		nxtCPos = 0;
		std::cout << "dest = " << currentDest << std::endl;
		return currentDest;
	}

	int i = 0;
	while (currentCommand[i] != '\0') {

		if (currentCommand[i] == '=') {
			nxtCPos = i + 1;
			break;
		}
		currentDest.push_back(currentCommand[i]);
		i++;
	}
	std::cout << "dest = " << currentDest << std::endl;

	return currentDest;
}

std::string parser::comp() {

	currentComp.clear();

	int i = nxtCPos;

	nxtCPos = 256;

	while (currentCommand[i] != '\0') {

		if (currentCommand[i] == ';') {
			nxtCPos = i + 1;
			break;
		}

		currentComp.push_back(currentCommand[i]);
		i++;
	}

	std::cout << "comp = " << currentComp << std::endl;

	return currentComp;
}

std::string parser::jump() {

	currentJump.clear();

	int i = nxtCPos;

	if (nxtCPos != 256) {
		while (currentCommand[i] != '\0') {

			if (currentCommand[i] == ';') {
				nxtCPos = i++;
				break;
			}
			currentJump.push_back(currentCommand[i]);
			i++;
		}
	}

	else
		currentJump.push_back('\0');

	std::cout << "jump = " << currentJump << std::endl;

	return currentJump;
}

void parser::endStream() {

	fileStream.close();
}

void parser::resetStream() {

	fileStream.clear();
	fileStream.seekg(0);
}
