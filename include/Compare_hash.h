#ifndef LAB_2_INCLUDE_COMPARE_HASH_H
#define LAB_2_INCLUDE_COMPARE_HASH_H

#include <iostream>
#include <fstream>
#include <string>

void save_hash_to_file(const std::string& message, const std::string& filename);

bool compare_hash(const std::string& other_message, const std::string& filename);

bool compare_string_hash(const std::string& message, const std::string& other_mesage);

#endif