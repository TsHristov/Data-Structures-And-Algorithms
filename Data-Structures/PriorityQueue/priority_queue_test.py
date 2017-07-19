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

    def test_get_max(self):
        max_key = self.pq.get_max()
        expected = [None, 'R', 'N', 'O', 'P', 'H', 'G', 'A', 'E', 'I']
        actual = self.pq.get_copy()
        self.assertEqual(expected, actual)
        self.assertEqual(max_key, 'T')

if __name__ == "__main__":
    unittest.main()
