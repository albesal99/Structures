#include <iostream>
#include "hash_quad.h"
#include <tuple>
#include <vector>
#include <string>

int main() {
    hash_quad ht(7);
    ht.insert("cat", 1);
    ht.insert("mouse", 2);
    ht.insert("dog", 2);
    std::cout << ht.hash_value("cat") << " " << ht.hash_value("dog") << " " << ht.hash_value("mouse") << std::endl;
    std::cout << ht.get_num_items() << std::endl;
    std::cout << ht.get_table_size() << std::endl;
    std::cout << ht.get_load_factor() << std::endl << std::endl;
    ht.insert("elephant", 12);
    std::cout << ht.hash_value("cat") << " " << ht.hash_value("dog") << " " << ht.hash_value("mouse") << " ";
    std::cout << ht.hash_value("elephant") << std::endl;
    std::cout << ht.get_num_items() << std::endl;
    std::cout << ht.get_table_size() << std::endl;
    std::cout << ht.get_load_factor() << std::endl << std::endl;
}