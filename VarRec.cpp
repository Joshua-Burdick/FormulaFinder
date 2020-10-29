#include "VarRec.h"

VarRec::VarRec() {}

void VarRec::select(std::string field) {
	if (field.at(0) == 'k') {
		type = 'k';
	}
	else if(field.at(0) == 'f') {
		type = 'f';
	}
	else {
		type = NULL;
	}
}

void VarRec::parse() {

	//TODO: KINEMATICS RECOGNITION
	if (type == 'k') {
		std::cout << "Input initial parameters: ";
		std::cin >> userIn; //Get user's variables and input
	}

	//TODO: FORCES RECOGNITION
	else if (type == 'f') {
		std::cout << "Input initial parameters: ";
		std::cin >> userIn; //Get user's variables and input
	}

	else if (type == NULL) {
		//TODO: AMBIGUOUS FORM
	}
}