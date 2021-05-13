#include "VarRec.h"

VarRec::VarRec() {}

void VarRec::parse(string input) {

	varArr = split(input, ' ');
	for (auto i : varArr) { //**DEBUGGING**
		cout << i << endl;
	}
	cout << endl;

	for (string i : varArr) {
		string search = "";
		if (i == varArr[0]) {
			search = convert(i);
		}
		else {
			for (int j = 0; j < i.length(); j++) { //if it's a letter add to the string (the unit type)
				cout << i.at(j) << " " << isalpha(i.at(j)) << " "; //**DEBUGGING**
				if (isalpha(i.at(j))) {
					search += i.at(j);
				}
				else if (i.at(j) == '/') { //catch slashes for fractions
					search += i.at(j);
				}
				else if (i.at(j) == '^' && isdigit(i.at(j + 1))) { //catch exponents (i.e. acceleration)
					search += i.at(j);
					search += i.at(j + 1);
				}
				cout << endl;
			}
		}
		cout << search << endl << endl; //**DEBUGGING**
		find(search);
		cout << key << endl << endl;
	}

	//Printing the formula -- NULL if error, ignores DONE, simply an indicator it was already printed
	if (key != "NULL" && key != "DONE") {
		cout << formulas.at(key) << endl << endl;
	}
	else if (key == "NULL") {
		cout << "An error has occurred. It is likely the unit(s) wasn't recognized. Please try again." << endl << endl;
	}
}

//Logic for determining which variable the input value is
void VarRec::find(string var) {

	if (var == "m") {
		key[0] = '1';
	}
	//VELOCITIES -- w/ two of them, need to handle determining which it is.
	else if (var == "m/s") {
		if (key[1] == '1') {
			key[2] = '1';
		}
		else if (key[2] == '1') {
			key[1] = '1';
		}
		else {
			if (key[4] == '1') {
				key[1] = '1';
			}
			else if (key.at(4) == '0') {
				key[1] = '1';
				key[2] = '1';
			}
		}
	}
	else if (var == "m/s^2") {
		key[3] = '1';
	}
	else if (var == "s") {
		key[4] = '1';
	}
	else if (var == "N" && key[11] == '0') {
		key[5] = '1';
	}
	else if (var == "kg") {
		key[6] = '1';
	}
	//Normal force and parallel force, it states to use first w/ normal (into slope) and second w/ parallel (down slope)
	else if (var == "N" && key.at(11) == '1') {
		cout << "Normal force (force into the slope): " << formulas.at("000000110001") << endl;
		cout << "Parallel force (force down the slope): " << formulas.at("000000101001") << endl;
		key = "DONE"; //Results already printed
	}
	else if (var == "") {
		key[10] = '1';
	}
	else if (var == "deg" || var == "rad") {
		key[11] = '1';
	}
	else {
		key = "NULL"; //if it's not a recognized variable
	}
}

string VarRec::convert(string in) {
	string search;

	if (in == "x") {
		search = "m";
	}
	else if (in == "v0" || in == "v") {
		search = "m/s";
	}
	else if (in == "a") {
		search = "m/s^2";
	}
	else if (in == "t") {
		search = "s";
	}
	else if (in == "F" || in == "Fn" || in == "Fp" || in == "Ff") {
		search = "N";
	}
	else if (in == "m") {
		search = "kg";
	}
	else if (in == "mu") {
		search = "";
	}
	else if (in == "theta") {
		search = "deg";
	}
	else {
		search = "NULL";
	}

	return search;
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