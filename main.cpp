#include "Inclusion.h"

//Global variables for init
VarRec rec;

//Interpret Commands
void Commands(std::string input, std::string params);

int main() {

	std::string input;
	std::string params;

	//Get the subject
	std::cout << "Enter the subject here (type 'skip' if unsure): ";
	std::getline(std::cin, input);
	std::cout << std::endl;

	//Get initial variables
	std::cout << "Enter initial paramters: ";
	std::getline(std::cin, params);
	std::cout << std::endl;

	Commands(input, params);

	return 0;
}

void Commands(std::string input, std::string params) {
	rec.select(input, params);
	rec.parse();
}