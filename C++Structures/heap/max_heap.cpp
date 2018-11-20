//
// Created by Alberto Salmeron on 11/17/18.
//

#include "max_heap.h"

#define CAPACITY 50

class MaxHeap {
    int capacity;
    int num_items;
    int *heap;

public:
    MaxHeap(int capacity = CAPACITY);

    bool is_full();
    bool is_empty();
    int get_capacity();
    int get_size();
    int peek();
    bool enqueue(int);
    int dequeue();
    void build_heap(int *, int);

private:
    void percolate_up(int);
    void percolate_down(int);
    void swap(int, int);
    int max_child(int);
};

MaxHeap::MaxHeap(int capacity) {
    heap = new int[capacity + 1];
    capacity = capacity;
    num_items = 0;
}

bool MaxHeap::is_full() {
    return num_items == capacity;
}

bool MaxHeap::is_empty() {
    return num_items == 0;
}

int MaxHeap::get_capacity() {
    return capacity;
}

int MaxHeap::get_size() {
    return num_items;
}

int MaxHeap::peek() {
    if (is_empty()) {
        return 0;
    }
    return heap[1];
}

void MaxHeap::swap(int current_index, int parent_index) {
    int temp = heap[current_index];
    heap[current_index] = heap[parent_index];
    heap[parent_index] = temp;
}

void MaxHeap::percolate_up(int index) {
    int parent_index = index / 2;
    int current_index = index;
    while (parent_index > 0 and heap[current_index] >= heap[parent_index]) {
        swap(current_index, parent_index);
        current_index = parent_index;
        parent_index = parent_index / 2;
    }
}

bool MaxHeap::enqueue(int item) {
    if (is_full()) {
        return false;
    }
    num_items++;
    heap[num_items] = item;
    percolate_up(num_items);
    return true;
}

int MaxHeap::max_child(int index) {
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

void MaxHeap::percolate_down(int index) {
    while (index * 2 <= get_size()) {
        int max = max_child(index);
        if ((heap[index] != 0 and heap[max] != 0) and (heap[index] < heap[max])) {
            swap(index, max);
        }
        index = max;
    }
}

int MaxHeap::dequeue() {
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

void MaxHeap::build_heap(int *arr, int array_size) {
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
