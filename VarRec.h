#pragma once
#include "Inclusion.h"

class VarRec {

private:
	char type;
	std::string params;
public:
	VarRec();
	void select(std::string field, std::string input);
	void parse();
};