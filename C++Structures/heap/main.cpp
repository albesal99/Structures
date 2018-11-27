#include <iostream>
#include "max_heap.h"
using namespace std;

int main() {
    max_heap heap(4);
    cout << heap.get_capacity() << endl;
    int arr[] = {2, 9, 7, 6, 5, 8};
    heap.heap_sort_descending(arr, 6);
    cout << heap.get_capacity() << endl;
    for (int i = 0; i < 6; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}