import unittest
import queue


class TestQueue(unittest.TestCase):
    def setUp(self):
        self.queue = queue.Queue()
        self.other = queue.Queue()

    def test_enqueue(self):
        self.queue.enqueue('a')
        first = self.queue._queue._first
        last = self.queue._queue._last
        self.assertTrue(first == last)
        self.queue.enqueue('b')
        self.assertEqual(self.queue.first(), 'a')
        self.assertEqual(self.queue.last(), 'b')

    def test_dequeue(self):
        with self.assertRaises(queue.EmptyQueue):
            self.queue.dequeue()
        self.queue.enqueue('a')
        self.queue.enqueue('b')
        self.assertEqual(self.queue.dequeue(), 'a')
        self.assertEqual(self.queue.dequeue(), 'b')

    def test_get_first(self):
        with self.assertRaises(queue.EmptyQueue):
            self.queue.first()
        self.queue.enqueue('a')
        self.queue.enqueue('b')
        size = len(self.queue)
        self.assertEqual(self.queue.first(), 'a')
        self.assertEqual(len(self.queue), size)

    def test_get_last(self):
        with self.assertRaises(queue.EmptyQueue):
            self.queue.last()
        self.queue.enqueue('a')
        self.queue.enqueue('b')
        size = len(self.queue)
        self.assertEqual(self.queue.last(), 'b')
        self.assertEqual(len(self.queue), size)

    def test_is_empty(self):
        self.assertTrue(self.queue.is_empty())
        self.queue.enqueue('a')
        self.assertFalse(self.queue.is_empty())

    def test_len(self):
        self.assertEqual(len(self.queue), 0)
        self.queue.enqueue('a')
        self.assertEqual(len(self.queue), 1)

    def test_equal(self):
        self.assertTrue(self.queue == self.queue)
        self.assertTrue(self.queue == self.other)
        self.queue.enqueue(1)
        self.other.enqueue(1)
        self.assertTrue(self.queue == self.other)

    def test_not_equal(self):
        self.queue.enqueue(1)
        self.assertTrue(self.queue != self.other)

if __name__ == "__main__":
    unittest.main()
