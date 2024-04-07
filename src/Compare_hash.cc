#include "../include/Compare_hash.h"
#include "../include/Pearson_hash.h"

void save_hash_to_file(const std::string& message, const std::string& filename) {
    PearsonHash  pearson_hash;
    std::ofstream file(filename);
    if (file.is_open()) {
        file << pearson_hash(message);
        file.close();
    }
    else {
        std::cerr << "Ошибка открытия файла для записи" << std::endl;
    }
}

bool compare_hash(const std::string& other_message, const std::string& filename) {
    PearsonHash  pearson_hash;
    std::ifstream file(filename);
    if (file.is_open()) {
        size_t saved_hash;
        file >> saved_hash;
        file.close();
        return saved_hash == pearson_hash(other_message);
    }
    else {
        std::cerr << "Ошибка открытия файла для чтения" << std::endl;
        return false;
    }
}

bool compare_string_hash(const std::string& message, const std::string& other_message) {
    PearsonHash  pearson_hash;
    return pearson_hash(message) == pearson_hash(other_message);
}