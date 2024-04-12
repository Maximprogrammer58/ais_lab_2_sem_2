#include "../include/Random.h"

std::string generate_random_string(int length) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    std::string randomString;
    for (int i = 0; i < length; ++i) {
        randomString += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return randomString;
}

void fill_hash_table_random_string(size_t count, HashTable<std::string, std::string, PearsonHash, StringEqual>& table) {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    for (size_t i = 0; i < count; ++i) {
        table.insert(generate_random_string((std::rand() % 10) + 1), generate_random_string((std::rand() % 10) + 1));
    }
}