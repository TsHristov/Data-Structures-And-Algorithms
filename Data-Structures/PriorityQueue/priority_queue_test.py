import unittest
import priority_queue


class TestPriorityQueue(unittest.TestCase):
    def setUp(self):
        self.pq = priority_queue.PriorityQueue(['T', 'N', 'R', 'P', 'H', 'O', 'A', 'E', 'I', 'G'])

    def test_insert(self):
        self.pq.insert('S')
        expected = [None, 'T', 'S', 'R', 'P', 'N', 'O', 'A', 'E', 'I', 'G', 'H']
        actual = self.pq.get_copy()
        self.assertEqual(expected, actual)


if __name__ == "__main__":
    unittest.main()
