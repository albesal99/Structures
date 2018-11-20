//
// Created by Alberto Salmeron on 11/17/18.
//

#ifndef HEAP_MAX_HEAP_H
#define HEAP_MAX_HEAP_H


class max_heap {
public:
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


#endif //HEAP_MAX_HEAP_H
