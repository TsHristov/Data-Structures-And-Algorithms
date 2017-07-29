import unittest
import stack


class TestStack(unittest.TestCase):
    def test_push(self):
        stack_test = stack.Stack()
        stack_test.push(1)
        stack_test.push(2)
        self.assertTrue(not stack_test.is_empty())

    def test_pop(self):
        stack_test = stack.Stack()
        stack_test.push(1)
        stack_test.push(2)
        self.assertEqual(stack_test.pop(), 2)
        self.assertEqual(stack_test.pop(), 1)

    def test_top(self):
        stack_test = stack.Stack()
        with self.assertRaises(stack.EmptyStack):
            stack_test.top()
        stack_test.push(1)
        stack_test.push(2)
        self.assertEqual(stack_test.top(), 2)
        self.assertEqual(len(stack_test), 2)

    def test_is_empty(self):
        stack_test = stack.Stack()
        self.assertTrue(stack_test.is_empty())
        stack_test.push(1)
        self.assertTrue(not stack_test.is_empty())

    def test_len(self):
        stack_test = stack.Stack()
        self.assertEqual(len(stack_test), 0)
        stack_test.push(1)
        stack_test.push(2)
        self.assertEqual(len(stack_test), 2)

    def test_equal(self):
        stack_test_1 = stack.Stack()
        stack_test_2 = stack.Stack()
        self.assertTrue(stack_test_1 == stack_test_1)
        self.assertTrue(stack_test_2 == stack_test_2)
        self.assertTrue(stack_test_1 == stack_test_2)
        stack_test_1.push(1)
        stack_test_1.push(2)
        stack_test_2.push(1)
        stack_test_2.push(2)
        self.assertTrue(stack_test_1 == stack_test_2)

    def test_not_equal(self):
        stack_test_1 = stack.Stack()
        stack_test_2 = stack.Stack()
        stack_test_2.push(1)
        self.assertTrue(stack_test_1 != stack_test_2)

if __name__ == "__main__":
    unittest.main()
