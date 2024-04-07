#include "include/HashTable.h"
#include "include/Random.h"


struct CustomIntHash {
    size_t operator()(int  key) const {
        return key;
    }
};

int main() {
    HashTable<int, int, CustomIntHash> table(10);
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