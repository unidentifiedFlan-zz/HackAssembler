#pragma once
class code {

	std::fstream hackFile;
	char binCommand[16];

public:
	code(std::string file);
	void A_Code(int currSymbol);
	void dest(std::string currDest, std::string &file);
	void comp(std::string currComp, std::string &file);
	void jump(std::string currJump, std::string &file);
	void writeHack();
	void endStream();
};

