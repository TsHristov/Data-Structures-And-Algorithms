import unittest
import deque


class TestDeque(unittest.TestCase):
    def setUp(self):
        self.deque = deque.Deque()

    def test_insert_first(self):
        self.deque.insert_first('a')
        self.assertEqual(self.deque._header._next._data, 'a')
        self.assertEqual(self.deque._trailer._previous._data, 'a')

    def test_insert_last(self):
        self.deque.insert_last('a')
        self.assertEqual(self.deque._header._next._data, 'a')
        self.assertEqual(self.deque._trailer._previous._data, 'a')
        self.deque.insert_last('b')
        self.assertEqual(self.deque._header._next._data, 'a')
        self.assertEqual(self.deque._trailer._previous._data, 'b')

    def test_delete_first(self):
        with self.assertRaises(deque.Empty):
            self.deque.delete_first()
        self.deque.insert_first('a')
        self.deque.insert_first('b')
        self.assertEqual(self.deque.delete_first(), 'b')
        self.assertEqual(self.deque.delete_first(), 'a')

    def test_delete_last(self):
        with self.assertRaises(deque.Empty):
            self.deque.delete_last()
        self.deque.insert_first('b')
        self.deque.insert_first('a')
        self.assertEqual(self.deque.delete_last(), 'b')
        self.assertEqual(self.deque.delete_last(), 'a')

    def test_get_first(self):
        with self.assertRaises(deque.Empty):
            self.deque.first()
        self.deque.insert_first('b')
        self.deque.insert_first('a')
        size = len(self.deque)
        self.assertEqual(self.deque.first(), 'a')
        self.assertEqual(len(self.deque), size)

    def test_get_last(self):
        with self.assertRaises(deque.Empty):
            self.deque.last()
        self.deque.insert_first('b')
        self.deque.insert_first('a')
        size = len(self.deque)
        self.assertEqual(self.deque.last(), 'b')
        self.assertEqual(len(self.deque), size)

if __name__ == "__main__":
    unittest.main()
