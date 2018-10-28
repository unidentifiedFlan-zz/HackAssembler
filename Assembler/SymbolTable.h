#pragma once
class symbolTable {

	std::map<std::string, int> symTable;

public:
	symbolTable();
	void addEntry(std::string symbol, int &address);
	bool contains(std::string symbol);
	int getAddress(std::string symbol);
};