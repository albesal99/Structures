#include <iostream>
#include "hash_quad.h"
#include <tuple>
#include <vector>
#include <string>

int main() {
    hash_quad ht(7);
    ht.insert("cat", 1);
    ht.insert("dog", 2);
    ht.insert("mouse", 2);
    std::cout << ht.get_index("cat") << " " << ht.get_index("dog") << " " << ht.get_index("mouse") << std::endl;
    std::cout << "num items = " << ht.get_num_items() << std::endl;
    std::cout << "table size = " << ht.get_table_size() << std::endl;
    std::cout << "load factor = " << ht.get_load_factor() << std::endl << std::endl;
    ht.insert("elephant", 12);
    std::cout << ht.get_index("cat") << " " << ht.get_index("dog") << " " << ht.get_index("mouse") << " ";
    std::cout << ht.get_index("elephant") << std::endl;
    std::cout << "num items = " << ht.get_num_items() << std::endl;
    std::cout << "table size = " << ht.get_table_size() << std::endl;
    std::cout << "load factor = " << ht.get_load_factor() << std::endl << std::endl;
    std::vector<std::string> keys = ht.get_all_keys();
    for (int i = 0; i < keys.size(); i++) {
        std::cout << keys.at(i) << " ";
    }
}