#include "Inclusion.h"
#include "VarRec.h";

//Global init
VarRec rec;

int main() {
	
	string params;

	//Get initial variables
	cout << "Enter initial paramters: ";
	getline(cin, params);
	cout << endl;

	rec.parse(params);

	return 0;
}