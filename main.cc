#include "include/HashTable.h"

int main() {
    HashTable<int, int> table(3);
    table.insert(1, 1);
    table.insert(2, 2);
    table.insert(4, 4);
    table.insert(22, 22);
    table.insert_or_assign(50, 0);
    table[1] = 0;
    table.print();
 
    return 0;
}