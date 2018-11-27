//
// Created by Alberto on 11/26/2018.
//
#include <tuple>
#include <string>
#include <vector>

#ifndef HASH_TABLE_HASH_QUAD_H
#define HASH_TABLE_HASH_QUAD_H

#define TABLE_SIZE 191

class hash_quad {
public:
    int table_size;
    int num_items;
    std::tuple<std::string, std::vector<int>> *hash_table;
    hash_quad(int table_size = TABLE_SIZE);
    void insert(std::string, int);
    void rehash(std::tuple<std::string, std::vector<int>> *);
    int hash_value(std::string);
    bool in_table(std::string);
    int get_index(std::string);
    std::vector<std::string> get_all_keys();
    int get_num_items();
    int get_table_size();
    double get_load_factor();
};


#endif //HASH_TABLE_HASH_QUAD_H
