#pragma once
#include "Inclusion.h"

class VarRec {

private:
	char type;
	std::string params;
	std::vector<std::string> varArr[];

	template<char delimiter>
	class WordDelimitedBy : public std::string
	{};

public:
	VarRec();
	void select(std::string field, std::string input);
	void parse();
};