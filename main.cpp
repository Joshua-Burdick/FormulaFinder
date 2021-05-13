#include "Inclusion.h"
#include "VarRec.h";

//Global init
VarRec rec;

int main() {
	
	string params; //Parameters for formulas
	
	//Get initial variables
	params = "";
	cout << "Enter initial paramters: ";
	getline(cin, params);
	cout << endl;

	rec.parse(params);

	return 0;
}