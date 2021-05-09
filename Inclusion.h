#pragma once

//External Libraries
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

//Formula Dictionary
// pos | initial vel. | final vel. | accel. | time | force | mass | normal force | force parallel (slope) | force of friction | coeff. of friction | angle (slope)
// x | v0 | v | a | t | F | m | Fn | Fp | Ff | mu | theta
const static std::unordered_map<std::string, std::string> formulas = {
	{"111010000000", "x = x0 + avg[v]*t"},
	{"011000000000", "avg[v] = (v0 + v)/2"},
	{"011110000000", "v = v0 + a*t"},
	{"110110000000", "x = x0 + v0*t + (1/2)*a*(t^2)"},
	{"111100000000", "v^2 = v0^2 + 2a(x - x0)"},
	{"000101100000", "F = m*a"},
	{"000000110001", "Fn = m*g*sin(theta)"},
	{"000000101001", "Fp = m*g*cos(theta)"},
	{"000000010110", "Ff = mu*Fn"}
};