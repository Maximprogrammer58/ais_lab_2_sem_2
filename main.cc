#include "include/HashTable.h"
#include "include/Random.h"
#include "include/Pearson_hash.h"
#include "include/Compare_hash.h"

int main() {
    setlocale(LC_ALL, "Rus");
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

    // Проверка работы хеш-таблицы
    HashTable<int, int> table(10);
    table.insert(1, 1);
    table.insert(2, 2);
    table.insert(4, 4);
    table.insert(3, 3);
    table.insert(0, 9);
    table.erase(3);
    table.insert(13, 9);
    table.print();
    std::cout << table[13] << std::endl;
 
    return 0;
}