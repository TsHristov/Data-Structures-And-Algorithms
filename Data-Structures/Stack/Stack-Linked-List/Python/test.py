import unittest
import stack


class TestStack(unittest.TestCase):
    def setUp(self):
        self.stack = stack.Stack()
        self.other = stack.Stack()

    def test_push(self):
        self.stack.push(1)
        self.stack.push(2)
        self.assertFalse(self.stack.is_empty())

    def test_pop(self):
        self.stack.push(1)
        self.stack.push(2)
        self.assertEqual(self.stack.pop(), 2)
        self.assertEqual(self.stack.pop(), 1)

    def test_top(self):
        with self.assertRaises(stack.EmptyStack):
            self.stack.top()
        self.stack.push(1)
        self.stack.push(2)
        self.assertEqual(self.stack.top(), 2)
        self.assertEqual(len(self.stack), 2)

    def test_is_empty(self):
        self.assertTrue(self.stack.is_empty())
        self.stack.push(1)
        self.assertFalse(self.stack.is_empty())

    def test_len(self):
        self.assertEqual(len(self.stack), 0)
        self.stack.push(1)
        self.stack.push(2)
        self.assertEqual(len(self.stack), 2)

    def test_equal(self):
        self.assertTrue(self.stack == self.other)
        self.stack.push(1)
        self.stack.push(2)
        self.other.push(1)
        self.other.push(2)
        self.assertTrue(self.stack == self.other)

    def test_not_equal(self):
        self.stack.push(1)
        self.assertTrue(self.stack != self.other)

if __name__ == "__main__":
    unittest.main()
