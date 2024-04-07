#include "include/HashTable.h"
#include "include/Random.h"
#include "include/Pearson_hash.h"
#include "include/Compare_hash.h"

struct StringEqual {
    bool operator()(const std::string& a, const std::string& b) {
        return a == b;
    }
};

int main() {
    // Проверка работы хеш-таблицы
    HashTable<std::string, int, PearsonHash, StringEqual> table(10);
    table.insert("a", 1);
    table.insert("b", 2);
    table.insert("d", 4);
    table.insert("c", 3);
    table.insert_or_assign("a", 2);
    table.erase("c");
    table.print();

    setlocale(LC_ALL, "Rus");
    PearsonHash  pearson_hash;
    // Проверка хеш-функции Пирсона для строк
    std::string message, filename;
    std::cout << "Введите строку: ";
    std::getline(std::cin, message);
    std::cout << "Введите имя файла для сохранения хэша: ";
    std::cin >> filename;

    std::cout << "Хэш строки " << message << " : " << pearson_hash(message) << std::endl;
    save_hash_to_file(message, filename);

    std::string other_message = generateRandomString(5);
    std::cout << "Хэш строки " << other_message << " : " << pearson_hash(other_message) << std::endl;

    if (compare_hash(other_message, filename)) 
        std::cout << "Хэши совпадают" << std::endl;
    else 
        std::cout << "Хэши не совпадают" << std::endl;
 
    return 0;
}