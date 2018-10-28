#pragma once
#include "stdafx.h"
#include "Code.h"
#include "Parser.h"
#include "SymbolTable.h"

class HackAssembler {

	parser _parser;
	symbolTable _symTable;
	code _code;
public:
	HackAssembler(std::string &file);
	void buildSymbolTable();
	void assembleA_Code(int &RAMAddress);
	void assembleC_Code(std::string &file);
};