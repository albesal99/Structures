//
// Created by Alberto Salmeron on 11/17/18.
//

#ifndef HEAP_MAX_HEAP_H
#define HEAP_MAX_HEAP_H

#define CAPACITY 50

class max_heap {
    int capacity;
    int num_items;
    int *heap;
private:
    void percolate_up(int);
    void percolate_down(int);
    void swap(int, int);
    int max_child(int);
public:
    max_heap(int capacity = CAPACITY);
    bool is_full();
    bool is_empty();
    int get_capacity();
    int get_size();
    int peek();
    bool enqueue(int);
    int dequeue();
    void build_heap(int *, int);
    void contents();
    void heap_sort_ascending(int *, int);
    void heap_sort_descending(int *, int);
};


#endif //HEAP_MAX_HEAP_H
