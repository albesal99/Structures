#include <iostream>
#include "max_heap.h"

int main() {
    max_heap MaxHeap;
    int arr[] = {2, 9, 7, 6, 5, 8};
    MaxHeap.build_heap(arr, 6);
    MaxHeap.enqueue(10);
    std::cout << " " << MaxHeap.peek();
    return 0;
}