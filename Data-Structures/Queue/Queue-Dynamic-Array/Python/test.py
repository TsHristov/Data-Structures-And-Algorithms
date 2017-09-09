import unittest
import queue


class TestQueue(unittest.TestCase):
    def setUp(self):
        self.queue = queue.Queue()
        self.other = queue.Queue()

    def test_enqueue(self):
        self.queue.enqueue('a')
        self.queue.enqueue('b')
        self.assertEqual(self.queue.first(), 'a')

    def test_dequeue(self):
        with self.assertRaises(queue.Empty):
            self.queue.dequeue()
        self.queue.enqueue('a')
        self.queue.enqueue('b')
        self.assertEqual(self.queue.dequeue(), 'a')
        self.assertEqual(self.queue.dequeue(), 'b')

    def test_get_first(self):
        with self.assertRaises(queue.Empty):
            self.queue.first()
        self.queue.enqueue('a')
        self.queue.enqueue('b')
        self.assertEqual(self.queue.first(), 'a')

    def test_is_empty(self):
        self.assertTrue(self.queue.is_empty())
        self.queue.enqueue('a')
        self.assertFalse(self.queue.is_empty())

    def test_len(self):
        self.assertEqual(len(self.queue), 0)
        self.queue.enqueue('a')
        self.assertEqual(len(self.queue), 1)

if __name__ == "__main__":
    unittest.main()
