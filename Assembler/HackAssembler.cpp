//Nand2Tetris == Project 06: Assembler for the Hack computer

#include "stdafx.h"
#include "HackAssembler.h"


bool try_stoi(int & i, const std::string & s) {
	try {
		size_t pos;
		i = stoi(s, &pos);
		return pos == s.size();
	}
	catch (const std::invalid_argument&) {
		return false;
	}
}

void HackAssembler::buildSymbolTable() {

	int ROMAddress = 0;

	while (_parser.hasMoreCommands()) {

		_parser.advance();

		if (_parser.commandType() == "L_COMMAND")
			_symTable.addEntry(_parser.symbol(), ROMAddress);

		if (_parser.commandType() == "A_COMMAND" || _parser.commandType() == "C_COMMAND")
			ROMAddress++;
	}
}

void HackAssembler::assembleA_Code(int &RAMAddress) {

	std::string sym = _parser.symbol();

	int address;

	if (try_stoi(address, sym))
		_code.A_Code(address);


	else if (_symTable.contains(_parser.symbol())) {

		_code.A_Code(_symTable.getAddress(_parser.symbol()));
	}

	else {

		_symTable.addEntry(_parser.symbol(), RAMAddress);
		_code.A_Code(RAMAddress);
		RAMAddress++;
	}

	_code.writeHack();
}

void HackAssembler::assembleC_Code(std::string &file) {

	_code.dest(_parser.dest(), file);
	_code.comp(_parser.comp(), file);
	_code.jump(_parser.jump(), file);
	_code.writeHack();
}

HackAssembler::HackAssembler(std::string &file) : _parser(parser(file)), _code(code(file)){

	buildSymbolTable();
	_parser.resetStream();

	int RAMAddress = 16;

	while (_parser.hasMoreCommands()) {

		std::cout << "Parsing..." << std::endl;

		_parser.advance();

		if (_parser.commandType() == "A_COMMAND") {

			assembleA_Code(RAMAddress);
		}

		if (_parser.commandType() == "C_COMMAND") {
			assembleC_Code(file);
		}

	}

	_parser.endStream();
	_code.endStream();
}
