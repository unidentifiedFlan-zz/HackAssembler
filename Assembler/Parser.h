#pragma once
class parser {

	std::fstream fileStream;
	char currentCommand[256];
	std::string commType;
	std::string sym;
	std::string currentDest;
	std::string currentComp;
	std::string currentJump;
	int nxtCPos;

public:
	parser(std::string file);
	bool hasMoreCommands();
	void advance();
	std::string commandType();
	std::string symbol();
	std::string dest();
	std::string comp();
	std::string jump();
	void endStream();
	void resetStream();
};

