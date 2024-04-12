#ifndef LAB_2_INCLUDE_EQUAL_H
#define LAB_2_INCLUDE_EQUAL_H

#include <string>

struct StringEqual {
    bool operator()(const std::string& a, const std::string& b);
};

struct DoubleEqual {
    bool operator()(double a, double b);
};

#endif