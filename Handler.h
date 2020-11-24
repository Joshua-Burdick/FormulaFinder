#pragma once
#include "Inclusion.h"

class Handler {
private:
public:
	Handler();
	const std::vector<std::string> split(const std::string& s, const char& c); //From http://www.cplusplus.com/articles/2wA0RXSz/
};