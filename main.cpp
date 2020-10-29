#include "Inclusion.h"

//Global variables for init
VarRec rec;

//Interpret Commands
void Commands(std::string input);

int main() {

	std::string input;
	
	std::cout << "Enter the subject here (type 'skip' if unsure): ";
	std::cin >> input;
	std::cout << std::endl;

	Commands(input);

	return 0;
}

void Commands(std::string input) {
	rec.select(input);
}