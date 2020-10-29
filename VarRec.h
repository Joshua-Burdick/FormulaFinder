#pragma once
#include "Inclusion.h"

class VarRec {

private:
	char type;
	std::string userIn;
public:
	VarRec();
	void select(std::string field);
	void parse();
};