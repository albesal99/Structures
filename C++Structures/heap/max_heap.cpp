//
// Created by Alberto Salmeron on 11/17/18.
//

#include <iostream>
#include "max_heap.h"
using namespace std;

max_heap::max_heap(int size) {
    capacity = size;
    heap = new int[size + 1];
    num_items = 0;
}

bool max_heap::is_full() {
    return num_items == capacity;
}

bool max_heap::is_empty() {
    return num_items == 0;
}

int max_heap::get_capacity() {
    return capacity;
}

int max_heap::get_size() {
    return num_items;
}

int max_heap::peek() {
    if (is_empty()) {
        return 0;
    }
    return heap[1];
}

void max_heap::swap(int current_index, int parent_index) {
    int temp = heap[current_index];
    heap[current_index] = heap[parent_index];
    heap[parent_index] = temp;
}

void max_heap::percolate_up(int index) {
    int parent_index = index / 2;
    int current_index = index;
    while (parent_index > 0 and heap[current_index] >= heap[parent_index]) {
        swap(current_index, parent_index);
        current_index = parent_index;
        parent_index = parent_index / 2;
    }
}

bool max_heap::enqueue(int item) {
    if (is_full()) {
        return false;
    }
    num_items++;
    heap[num_items] = item;
    percolate_up(num_items);
    return true;
}

int max_heap::max_child(int index) {
    if (index * 2 + 1 > get_size()) {
        return index * 2;
    } else {
        if ((heap[index * 2] != 0 and heap[index * 2 + 1] != 0) and (heap[index * 2] > heap[index * 2 + 1])) {
            return index * 2;
        } else {
            return index * 2 + 1;
        }
    }
}

void max_heap::percolate_down(int index) {
    while (index * 2 <= get_size()) {
        int max = max_child(index);
        if ((heap[index] != 0 and heap[max] != 0) and (heap[index] < heap[max])) {
            swap(index, max);
        }
        index = max;
    }
}

int max_heap::dequeue() {
    if (is_empty()) {
        return 0;
    }
    int max_item = heap[1];
    heap[1] = heap[num_items];
    heap[num_items] = 0;
    percolate_down(1);
    num_items--;
    return max_item;
}

void max_heap::build_heap(int *arr, int array_size) {
    if (capacity < array_size) {
        capacity = array_size;
        delete[] heap;
        heap = new int[array_size + 1];
    }
    if (array_size > 0) {
        int index = 1;
        for (int i = 0; i < array_size; i++) {
            heap[index] = arr[index - 1];
            index++;
            num_items++;
        }
        int i = array_size / 2;
        while (i > 0) {
            percolate_down(i);
            i--;
        }
    }
}

void max_heap::contents() {
    for (int i = 1; i <= num_items; i++) {
        cout << heap[i] << " ";
    }
}

void max_heap::heap_sort_ascending(int *arr, int arr_size) {
    build_heap(arr, arr_size);
    for (int i = arr_size - 1; i >= 0; i--) {
        arr[i] = dequeue();
    }
}

void max_heap::heap_sort_descending(int *arr, int arr_size) {
    build_heap(arr, arr_size);
    for (int i = 0; i < arr_size; i++) {
        arr[i] = dequeue();
    }
}
