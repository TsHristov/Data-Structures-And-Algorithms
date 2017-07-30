import unittest
import linked_list

class TestLinkedList(unittest.TestCase):
    def setUp(self):
        self.test_list = linked_list.LinkedList()

    def test_push_back(self):
        self.test_list.push_back('a')
        self.assertTrue(self.test_list._first == self.test_list._last)
        self.test_list.push_back('b')
        self.assertTrue(self.test_list._first.data == 'a')
        self.assertTrue(self.test_list._last.data == 'b')

    def test_push_front(self):
        self.test_list.push_front('a')
        self.assertTrue(self.test_list._first == self.test_list._last)
        self.assertEqual(self.test_list._first.data, self.test_list._last.data)
        self.test_list.push_front('b')
        self.assertEqual(self.test_list._first.data, 'b')
        self.assertEqual(self.test_list._last.data, 'a')

    def test_pop_front(self):
        with self.assertRaises(linked_list.EmptyList):
            self.test_list.pop_front()
        self.test_list.push_back('a')
        self.test_list.push_back('b')
        self.assertEqual(self.test_list.pop_front(), 'a')
        self.assertEqual(self.test_list.pop_front(), 'b')

    def test_get_first(self):
        with self.assertRaises(linked_list.EmptyList):
            self.test_list.first()
        self.test_list.push_back('a')
        self.test_list.push_back('b')
        size = len(self.test_list)
        self.assertEqual(self.test_list.first(), 'a')
        # Make sure no elements were removed from the list
        self.assertEqual(size, len(self.test_list))

    def test_get_last(self):
        with self.assertRaises(linked_list.EmptyList):
            self.test_list.last()
        self.test_list.push_back('a')
        self.test_list.push_back('b')
        size = len(self.test_list)
        self.assertEqual(self.test_list.last(), 'b')
        # Make sure no elements were removed from the list
        self.assertEqual(size, len(self.test_list))

    def test_is_empty(self):
        self.assertTrue(self.test_list.is_empty())
        self.test_list.push_back('a')
        self.assertFalse(self.test_list.is_empty())

if __name__ == "__main__":
    unittest.main()
