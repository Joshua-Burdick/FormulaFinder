#pragma once
#include "Inclusion.h"

class VarRec {

private:
	std::vector<std::string> varArr;
	std::string key = "000000000000";
public:
	VarRec();
	void parse(std::string input);
	void find(std::string var);
	const std::vector<std::string> split(const std::string& s, const char& c);
};