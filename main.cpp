#include "Inclusion.h"
#include "VarRec.h";

//Global init
VarRec rec;

int main() {
	
	std::string params;

	//Get initial variables
	std::cout << "Enter initial paramters: ";
	std::getline(std::cin, params);
	std::cout << std::endl;

	rec.parse(params);

	return 0;
}