#include "VarRec.h"

VarRec::VarRec() {}

void VarRec::parse(std::string field, std::vector<std::string> input) {
	params = input;

	for (int i = 0; i < C_OVERLORD.size(); i++) {
		for (int j = 0; j < C_OVERLORD[i].size(); j++) {
			std::cout << C_OVERLORD[i][j] << std::endl;
		}
	}
}

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