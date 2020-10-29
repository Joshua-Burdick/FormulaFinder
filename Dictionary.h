#pragma once
#include "Inclusion.h"

//Kinematics
const std::string C_KO = "x = x0 + avg[v]*t";
const std::string C_KTW = "avg[v] = (v0 + v)/2";
const std::string C_KTH = "v = v0 + a*t"; //Constant a
const std::string C_KFO = "x = x0 + v0*t + (1/2)*a*(t^2)"; //Constant a
const std::string C_KFI = "v^2 = v0^2 + 2a(x - x0)"; //Constant a

const std::array<const std::string, 5> C_KINEARR = { C_KFO, C_KTW, C_KTH, C_KFO, C_KFI };

//Forces
const std::string C_F = "F = m*a";
const std::string C_FN = "Fn = m*g*sin(theta)";
const std::string C_FP = "Fp = m*g*cos(theta)";
const std::string C_FF = "Ff = mu*Fn"; //mu = coefficient of friction

const std::array<const std::string, 4> C_FORCEARR = { C_F, C_FN, C_FP, C_FF };