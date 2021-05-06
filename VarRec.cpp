#include "VarRec.h"

VarRec::VarRec() {}

void VarRec::parse(std::string input) {
	params = input;
	
}


//Found on Stack Overflow to split strings via delimiter into a vector
const std::vector<std::string> VarRec::split(const std::string& s, const char& c) {
	std::string buff{ "" };
	std::vector<std::string> v;

	for (auto n : s)
	{
		if (n != c) buff += n;

		else {
			if (n == c && buff != "") {
				v.push_back(buff);
				buff = "";
			}
		}
	}

	if (buff != "") v.push_back(buff);

	return v;
}