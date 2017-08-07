import unittest
import doubly_linked_list


class TestDoublyLinkedList(unittest.TestCase):
    def setUp(self):
        self.list = doubly_linked_list.DoublyLinkedList()

    def test_insert_first(self):
        self.list.insert_first('a')
        self.list.insert_first('b')
        first = self.list._header._next._data
        last = self.list._trailer._previous._data
        self.assertEqual(first, 'b')
        self.assertEqual(last, 'a')

    def test_insert_last(self):
        self.list.insert_last('a')
        self.list.insert_last('b')
        first = self.list._header._next._data
        last = self.list._trailer._previous._data
        self.assertEqual(first, 'a')
        self.assertEqual(last, 'b')

    def test_get_first(self):
        with self.assertRaises(doubly_linked_list.Empty):
            self.list.first()
        self.list.insert_first('a')
        self.list.insert_last('b')
        self.assertEqual(self.list.first(), 'a')

    def test_get_last(self):
        with self.assertRaises(doubly_linked_list.Empty):
            self.list.last()
        self.list.insert_first('a')
        self.list.insert_last('b')
        self.assertEqual(self.list.last(), 'b')

    def test_forward_iterator(self):
        with self.assertRaises(StopIteration):
            i = iter(self.list)
            next(i)
        self.list.insert_first('c')
        self.list.insert_first('b')
        self.list.insert_first('a')
        for node, value in zip(self.list, ['a', 'b', 'c']):
            self.assertEqual(node, value)

    def test_reverse_iterator(self):
        with self.assertRaises(StopIteration):
            i = reversed(self.list)
            next(i)
        self.list.insert_first('c')
        self.list.insert_first('b')
        self.list.insert_first('a')
        for node, value in zip(reversed(self.list), ['c', 'b', 'a']):
            self.assertEqual(node, value)

if __name__ == "__main__":
    unittest.main()
