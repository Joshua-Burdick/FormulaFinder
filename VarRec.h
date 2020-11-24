#pragma once
#include "Inclusion.h"

class VarRec {

private:
	std::string params;
	std::vector<std::string> varArr;
public:
	VarRec();
	void parse(std::string field, std::string input);
};