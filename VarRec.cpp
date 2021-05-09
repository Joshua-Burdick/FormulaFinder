#include "VarRec.h"

VarRec::VarRec() {}

void VarRec::parse(std::string input) {

	varArr = split(input, ' ');

	for (std::string i : varArr) {
		std::string search = i;
		//***TODO: TAKE OUT NUMBERS AT BEGINNING***
		find(search);
	}

	formulas.at(key);
}

//Logic for determining which variable the input value is
void VarRec::find(std::string var) {

	if (var == "m" || var == "meters") {
		key[0] = '1';
	}
	//***TODO: HANDLE VELOCITIES***
	else if (var == "m/s^2" || var == "meters/second^2") {
		key[4] = '1';
	}
	else if (var == "s" || var == "sec" || var == "seconds") {
		key[5] = '1';
	}
	else if (var == "N" || var == "Newtons") { //***TODO: INCORPORATE WITH Fn Fp Ff PROPERLY***
		key[6] = '1';
	}
	else if (var == "kg" || var == "kilograms") {
		key[7] = '1';
	}
	//***TODO: FORCE NORMAL, FORCE PARALLEL, AND FORCE FRICTION***
	else if (var == "") {
		key[11] = '1';
	}
	else if (var == "deg" || var == "degrees" || var == "rad" || var == "radians") {
		key[12] = '1';
	}
}

//Found on Stack Overflow to split strings via delimiter into a vector
const std::vector<std::string> VarRec::split(const std::string& s, const char& c) {
	std::string buff{ "" };
	std::vector<std::string> v;

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