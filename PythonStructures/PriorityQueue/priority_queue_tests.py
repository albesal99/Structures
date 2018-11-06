import unittest
from PriorityQueue.priority_queue import *

class TestList(unittest.TestCase):
    def test_is_empty(self):
        pq = PriorityQueue()
        self.assertTrue(pq.is_empty())
        pq.enqueue(25, 3)
        self.assertFalse(pq.is_empty())

    def test_enqueue_01(self):
        pq = PriorityQueue()
        pq.enqueue("haha", 5)
        pq.enqueue("lol", 2)
        pq.enqueue("omg", 7)
        pq.enqueue("LMAO", 1)
        pq.enqueue("LOOOOOL", 1)
        self.assertEqual(pq.__repr__(), "[(omg, 7), (haha, 5), (lol, 2), (LOOOOOL, 1), (LMAO, 1)]")

    def test_enqueue_02(self):
        pq = PriorityQueue()
        pq.enqueue("haha", 3)
        pq.enqueue("lol", 3)
        pq.enqueue("omg", 2)
        pq.enqueue("LMAO", 6)
        pq.enqueue("LOOOOOL", 1)
        self.assertEqual(pq.__repr__(), "[(LMAO, 6), (haha, 3), (lol, 3), (omg, 2), (LOOOOOL, 1)]")

    def test_front(self):
        pq = PriorityQueue()
        with self.assertRaises(IndexError):
            pq.front()

if __name__ == '__main__':
   unittest.main()
