#include <cmath>
#include <string>
#include "../include/Equal.h"

bool StringEqual::operator()(const std::string& a, const std::string& b) {
    return a == b;
}

bool DoubleEqual::operator()(double a, double b) {
    return abs(a - b) < 1e-10;
}