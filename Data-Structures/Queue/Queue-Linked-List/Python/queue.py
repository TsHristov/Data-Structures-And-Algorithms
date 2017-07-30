import sys
sys.path.insert(0, '../../../Linked-List/Python')
import linked_list


class EmptyQueue(Exception):
    pass


class QueueIterator(linked_list.ListIterator):
    pass


class Queue:
    def __init__(self):
        self._queue = linked_list.LinkedList()

    def enqueue(self, data):
        self._queue.push_back(data)

    def dequeue(self):
        if self.is_empty():
            raise EmptyQueue
        else:
            return self._queue.pop_front()

    def first(self):
        if self.is_empty():
            raise EmptyQueue
        else:
            return self._queue.first()

    def last(self):
        if self.is_empty():
            raise EmptyQueue
        else:
            return self._queue.last()

    def is_empty(self):
        return self._queue.is_empty()

    def __eq__(self, other):
        return self._queue.__eq__(other._queue)

    def __ne__(self, other):
        return not self.__eq__(other)

    def __iter__(self):
        """Returns and iterator that iterates the queue in FIFO order."""
        return QueueIterator(self._queue._first)

    def __len__(self):
        return len(self._queue)
