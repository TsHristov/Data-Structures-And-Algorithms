import unittest
import linked_list

class TestLinkedList(unittest.TestCase):
    def setUp(self):
        self.list = linked_list.LinkedList()
        self.other = linked_list.LinkedList()

    def test_push_back(self):
        self.list.push_back('a')
        self.assertTrue(self.list._first == self.list._last)
        self.list.push_back('b')
        self.assertTrue(self.list._first.data == 'a')
        self.assertTrue(self.list._last.data == 'b')

    def test_push_front(self):
        self.list.push_front('a')
        self.assertTrue(self.list._first == self.list._last)
        self.assertEqual(self.list._first.data, self.list._last.data)
        self.list.push_front('b')
        self.assertEqual(self.list._first.data, 'b')
        self.assertEqual(self.list._last.data, 'a')

    def test_pop_front(self):
        with self.assertRaises(linked_list.EmptyList):
            self.list.pop_front()
        self.list.push_back('a')
        self.list.push_back('b')
        self.assertEqual(self.list.pop_front(), 'a')
        self.assertEqual(self.list.pop_front(), 'b')

    def test_get_first(self):
        with self.assertRaises(linked_list.EmptyList):
            self.list.first()
        self.list.push_back('a')
        self.list.push_back('b')
        size = len(self.list)
        self.assertEqual(self.list.first(), 'a')
        # Make sure no elements were removed from the list
        self.assertEqual(size, len(self.list))

    def test_get_last(self):
        with self.assertRaises(linked_list.EmptyList):
            self.list.last()
        self.list.push_back('a')
        self.list.push_back('b')
        size = len(self.list)
        self.assertEqual(self.list.last(), 'b')
        # Make sure no elements were removed from the list
        self.assertEqual(size, len(self.list))

    def test_equal(self):
        self.assertTrue(self.list == self.list)
        self.assertTrue(self.list == self.other)
        self.list.push_back('a')
        self.other.push_back('a')
        self.assertTrue(self.list == self.other)

    def test_not_equal(self):
        self.list.push_back('a')
        self.assertTrue(self.list != self.other)
        
    def test_is_empty(self):
        self.assertTrue(self.list.is_empty())
        self.list.push_back('a')
        self.assertFalse(self.list.is_empty())

if __name__ == "__main__":
    unittest.main()
