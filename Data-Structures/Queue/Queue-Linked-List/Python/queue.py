import sys
sys.path.insert(0, '../../../Linked-List/Python')
from linked_list import Empty, Iterator, LinkedList


class Queue(LinkedList):

    def enqueue(self, data):
        self.push_back(data)

    def dequeue(self):
        if self.is_empty():
            raise Empty
        else:
            return self.pop_front()

    def __iter__(self):
        """Returns and iterator that iterates the queue in FIFO order."""
        return Iterator(self._first)
