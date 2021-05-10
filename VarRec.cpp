#include "VarRec.h"

VarRec::VarRec() {}

void VarRec::parse(string input) {

	varArr = split(input, ' ');

	for (string i : varArr) {
		string search = "";
		for (int j = 0; j < i.length(); j++) { //if it's a letter add to the string (the unit type)
			cout << i.at(j) << " " << isalpha(i.at(j)) << " ";
			if (isalpha(i.at(j))) {
				search += i.at(j);
			}
			else if (i.at(j) == '/') { //catch slashes for fractions
				search += i.at(j);
			}
			else if (i.at(j) == '^' && isdigit(i.at(j + 1))) { //catch exponents (i.e. acceleration)
				search += (i.at(j) + i.at(j+1));
			}
			cout << endl;
		}
		cout << search << endl << endl;
	}

	//formulas.at(key);
}

//Logic for determining which variable the input value is
void VarRec::find(string var) {

	if (var == "m") {
		key[0] = '1';
	}
	//***TODO: HANDLE VELOCITIES***
	else if (var == "m/s^2") {
		key[3] = '1';
	}
	else if (var == "s") {
		key[4] = '1';
	}
	else if (var == "N") { //***TODO: INCORPORATE WITH Fn Fp Ff PROPERLY***
		key[5] = '1';
	}
	else if (var == "kg") {
		key[6] = '1';
	}
	//***TODO: FORCE NORMAL, FORCE PARALLEL, AND FORCE FRICTION***
	else if (var == "") {
		key[10] = '1';
	}
	else if (var == "deg" || var == "rad") {
		key[11] = '1';
	}
}

//Found on Stack Overflow to split strings via delimiter into a vector
const vector<string> VarRec::split(const string& s, const char& c) {
	string buff{ "" };
	vector<string> v;

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