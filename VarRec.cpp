#include "VarRec.h"

VarRec::VarRec() {}

void VarRec::select(std::string field, std::string input) {
	params = input;

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