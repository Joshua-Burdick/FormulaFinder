#include "VarRec.h"

VarRec::VarRec() {}

void VarRec::select(std::string field, std::string input) {
	params = input;
	std::istringstream iss(params);

	if (field.at(0) == 'k') {
		type = 'k';
	}
	else if (field.at(0) == 'f') {
		type = 'f';
	}
	else {
		type = NULL;
	}
}

void VarRec::parse() {

	//TODO: KINEMATICS RECOGNITION
	if (type == 'k') {
		std::cout << "Selected: Kinematics" << std::endl;
		std::cout << params << std::endl;
		std::vector<std::string> results((std::istream_iterator<WordDelimitedBy<';'>>(iss)),
			std::istream_iterator<WordDelimitedBy<';'>>());
		for (int i = 0; i < results.size(); i++) {
			std::cout << results[i];
		}
	}

	//TODO: FORCES RECOGNITION
	else if (type == 'f') {
		std::cout << "Selected: Forces" << std::endl;
		std::cout << params << std::endl;
	}

	else if (type == NULL) {
		//TODO: AMBIGUOUS FORM
	}
}