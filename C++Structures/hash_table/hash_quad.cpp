//
// Created by Alberto on 11/26/2018.
//

#include <iostream>
#include "hash_quad.h"
#include <algorithm>
#include <vector>
#include <tuple>
#include <string>
#include <math.h>
using namespace std;

hash_quad::hash_quad(int size) {
    table_size = size;
    hash_table = new tuple<string, vector<int>>[size];
    num_items = 0;
}

int hash_quad::get_num_items() {
    return num_items;
}

int hash_quad::get_table_size() {
    return table_size;
}

double hash_quad::get_load_factor() {
    return num_items / (double)table_size;
}

int hash_quad::hash_value(string key) {
    long long index = 0;
    int key_length = key.length();
    int minimum = min(key_length, 8);
    for (int character = 0; character < minimum; character++) {
        index = 31 * index + key[character];
    }
    return (((index % get_table_size()) + get_table_size()) % get_table_size());
}

bool hash_quad::in_table(string key) {
    int hash_index = hash_value(key);
    int index = hash_index;
    int collisions = 0;
    while (get<0>(hash_table[hash_index]) != "" and get<0>(hash_table[hash_index]) != key) {
        collisions++;
        int col_index = pow(collisions, 2);
        col_index += index;
        col_index = (((col_index % get_table_size()) + get_table_size()) % get_table_size());
        hash_index = col_index;
    }
    return get<0>(hash_table[hash_index]) == key;
}

int hash_quad::get_index(string key) {
    int hash_index = hash_value(key);
    int index = hash_index;
    int collisions = 0;
    cout << key << ": ";
    while (get<0>(hash_table[hash_index]) != "" and get<0>(hash_table[hash_index]) != key) {
        collisions++;
        int col_index = pow(collisions, 2);
        col_index += index;
        col_index = (((col_index % get_table_size()) + get_table_size()) % get_table_size());
        hash_index = col_index;
    }
    if (get<0>(hash_table[hash_index]) == key) {
        return hash_index;
    }
}

void hash_quad::insert(string key, int value) {
    if (in_table(key)) {
        int index = get_index(key);
        get<1>(hash_table[index]).push_back(value);
    } else {
        int hash_index = hash_value(key);
        if (get<0>(hash_table[hash_index]) == "") {
            get<0>(hash_table[hash_index]) = key;
            get<1>(hash_table[hash_index]).push_back(value);
            num_items++;
        } else {
            int t_index = hash_index;
            int collisions = 0;
            while (get<0>(hash_table[hash_index]) != "" and get<0>(hash_table[hash_index]) != key) {
                collisions++;
                int col_index = pow(collisions, 2);
                col_index += t_index;
                col_index = (((col_index % get_table_size()) + get_table_size()) % get_table_size());
                hash_index = col_index;
            }
            get<0>(hash_table[hash_index]) = key;
            get<1>(hash_table[hash_index]).push_back(value);
            num_items++;
        }
        if (get_load_factor() > 0.5) {
            rehash(hash_table);
        }
    }
}

void hash_quad::rehash(tuple<string, vector<int>> *old_table) {
    int old_size = get_table_size();
    int new_size = get_table_size() * 2 + 1;
    hash_table = new tuple<string, vector<int>>[new_size];
    num_items = 0;
    table_size = new_size;
    for (int i = 0; i < old_size; i++) {
        if (get<0>(old_table[i]) != "") {
            for (int j = 0; j < get<1>(old_table[i]).size(); j++) {
                string key = get<0>(old_table[i]);
                vector<int> value = get<1>(old_table[i]);
                insert(key, value.at(j));
            }
        }
    }
    delete[] old_table;
}

vector<string> hash_quad::get_all_keys() {
    vector<string> keys;
    for (int i = 0; i < get_table_size(); i++) {
        if (get<0>(hash_table[i]) != "") {
            keys.push_back(get<0>(hash_table[i]));
        }
    }
    return keys;
}
