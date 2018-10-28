#include "stdafx.h"
#include "SymbolTable.h"


symbolTable::symbolTable() {

	symTable.emplace("SP", 0);
	symTable.emplace("LCL", 1);
	symTable.emplace("ARG", 2);
	symTable.emplace("THIS", 3);
	symTable.emplace("THAT", 4);
	symTable.emplace("R0", 0);
	symTable.emplace("R1", 1);
	symTable.emplace("R2", 2);
	symTable.emplace("R3", 3);
	symTable.emplace("R4", 4);
	symTable.emplace("R5", 5);
	symTable.emplace("R6", 6);
	symTable.emplace("R7", 7);
	symTable.emplace("R8", 8);
	symTable.emplace("R9", 9);
	symTable.emplace("R10", 10);
	symTable.emplace("R11", 11);
	symTable.emplace("R12", 12);
	symTable.emplace("R13", 13);
	symTable.emplace("R14", 14);
	symTable.emplace("R15", 15);
	symTable.emplace("SCREEN", 16384);
	symTable.emplace("KBD", 24576);

}

void symbolTable::addEntry(std::string symbol, int &address) {

	symTable.emplace(symbol, address);

}

bool symbolTable::contains(std::string symbol) {

	bool containsSymbol = false;

	if (symTable.find(symbol) != symTable.end())
		containsSymbol = true;

	return containsSymbol;
}


int symbolTable::getAddress(std::string symbol) {

	return symTable[symbol];
}