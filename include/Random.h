#ifndef LAB_2_INCLUDE_RANDOM_H
#define LAB_2_INCLUDE_RANDOM_H

#include <ctime> 
#include <cstdlib>

#include "../include/HashTable.h"
#include "../include/Equal.h"
#include "../include/Hash.h"


std::string generate_random_string(int length);

void fill_hash_table_random_string(size_t count, HashTable<std::string, std::string, PearsonHash, StringEqual>& table);

#endif