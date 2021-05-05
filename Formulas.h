#pragma once

#include "Inclusion.h"
//Formula Dictionary
// pos | initial vel. | final vel. | accel. | time | force | mass | accel. due to grav. | normal force | force parallel (slope) | force of friction | coeff. of friction | angle (slope)
// x | v0 | v | a | t | F | m | g | Fn | Fp | Ff | mu | theta
std::unordered_map<int, std::string> formulas = {
	{1110100000000, "x = x0 + avg[v]*t"},
	{0110000000000, "avg[v] = (v0 + v)/2"},
	{0111100000000, "v = v0 + a*t"},
	{1101100000000, "x = x0 + v0*t + (1/2)*a*(t^2)"},
	{1111000000000, "v^2 = v0^2 + 2a(x - x0)"},
	{0001011000000, "F = m*a"},
	{0000001110001, "Fn = m*g*sin(theta)"},
	{0000001101001, "Fp = m*g*cos(theta)"},
	{0000000010110, "Ff = mu*Fn"}
};