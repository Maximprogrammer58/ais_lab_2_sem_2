#include "../include/Hash.h"

size_t IntHash::operator()(int number) {
    return number;
}

size_t PearsonHash::operator()(const std::string& message) {
    size_t result = 0;
    for (auto letter : message) {
        result = pearson_table[result ^ letter];
    }
    return result;
}