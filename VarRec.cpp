#include "VarRec.h"

VarRec::VarRec() {}

void VarRec::parse(std::string field, std::string input) {
	params = input;

	//TODO: KINEMATICS RECOGNITION
	if (tolower(field.at(0)) == 'k') {
		std::cout << "Selected: Kinematics" << std::endl;
		std::cout << params << std::endl;
	}

	//TODO: FORCES RECOGNITION
	else if (tolower(field.at(0)) == 'f') {
		std::cout << "Selected: Forces" << std::endl;
		std::cout << params << std::endl;
	}
}