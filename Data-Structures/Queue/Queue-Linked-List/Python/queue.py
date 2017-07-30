import sys
sys.path.insert(0, '../../../Linked-List/Python')
import linked_list


class QueueIterator:
    def __init__(self, queue):
        self._current = queue._first

    def __iter__(self):
        return self

    def __next__(self):
        if not self._current:
            raise StopIteration
        else:
            current = self._current
            self._current = self._current.next
            return current


class EmptyQueue(Exception):
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

    def __iter__(self):
        return QueueIterator(self._queue)

    def __len__(self):
        return len(self._queue)
