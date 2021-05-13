#pragma once
#include "Inclusion.h"

class VarRec {

private:
	vector<string> varArr;
	string key = "000000000000";
public:
	VarRec();
	void parse(string input);
	void find(string var);
	string convert(string in);
	const vector<string> split(const string& s, const char& c);
};