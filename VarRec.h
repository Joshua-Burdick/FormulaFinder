#pragma once
#include "Formulas.h"

class VarRec {

private:
	std::string params;
	std::vector<std::string> varArr;
public:
	VarRec();
	void parse(std::string field, std::string input);
	const std::vector<std::string> split(const std::string& s, const char& c);
};