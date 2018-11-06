import unittest
from MaxHeap.max_heap import *


class TestList(unittest.TestCase):
    def test_01_enqueue(self):
        test_heap = MaxHeap(7)
        test_heap.make_heap([2, 9, 7, 6, 5, 8])
        insert = test_heap.insert(10)
        self.assertTrue(insert)
        self.assertEqual(test_heap.heap_representation(), [10, 6, 9, 2, 5, 7, 8])



if __name__ == '__main__':
    unittest.main()