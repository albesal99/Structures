class MaxHeap:
    def __init__(self, capacity):
        self.capacity = capacity
        self.num_items = 0
        self.heap_list = [None] * (capacity+1)

    def make_heap(self, array):
        if len(array) > 0:
            for i in array:
                self.insert(i)

    def insert(self, item):
        if self.is_full():
            return False
        self.num_items += 1
        self.heap_list[self.num_items] = item
        self.percolate_up(self.num_items)
        return True

    def percolate_up(self, index):
        parent_index = index // 2
        current_index = index
        while current_index > 0 and \
                self.heap_list[current_index] is not None and \
                self.heap_list[parent_index] is not None and \
                self.heap_list[current_index] > self.heap_list[parent_index]:
            self.swap_items(current_index, parent_index)
            current_index = parent_index
            parent_index = parent_index // 2

    def swap_items(self, child, parent):
        temp = self.heap_list[parent]
        self.heap_list[parent] = self.heap_list[child]
        self.heap_list[child] = temp

    def heap_representation(self):
        heap = self.heap_list
        heap = heap[1:self.num_items+1]
        return heap

    def get_max(self):
        if self.is_empty():
            raise IndexError("Heap is empty")
        max_item = self.heap_list[1]
        self.heap_list[1] = self.heap_list[self.num_items]
        self.heap_list[self.num_items] = max_item
        self.percolate_down(1)
        self.num_items -= 1
        return max_item

    def delete(self, item):
        if self.is_empty():
            raise IndexError("Cannot delete from an empty heap")
        current = 1
        while self.heap_list[current] != item:
            current += 1
            if current > self.num_items:
                return False

    def percolate_down(self, index):
        least = index
        left_child_index = 2 * index
        right_child_index = 2 * index + 1
        if left_child_index < self.size() and self.heap_list[least] > self.heap_list[left_child_index]:
            least = left_child_index
        if right_child_index < self.size() and self.heap_list[least] > self.heap_list[right_child_index]:
            least = right_child_index
        if least != index:
            self.swap_items(index, least)
            self.percolate_down(least)

    def is_full(self):
        return self.num_items == self.capacity

    def is_empty(self):
        return self.num_items == 0

    def size(self):
        return self.num_items
