class Empty(Exception):
    pass


class Queue:
    """ Queue implementation using circular array """

    DEFAULT_CAPACITY = 10

    def __init__(self):
        self._data  = [None] * Queue.DEFAULT_CAPACITY
        self._size  = 0
        self._front = 0

    def enqueue(self, data):
        if self._size == len(self._data):
            self.resize(2 * len(self._data))
        availabe_spot = (self._front + self._size) % len(self._data)
        self._data[availabe_spot] = data
        # Increase the count of elements:
        self._size += 1

    def dequeue(self):
        if self.is_empty():
            raise Empty
        # Set the removed first element to None
        dequeued = self._data[self._front]
        self._data[self._front] = None
        # Update the front index:
        self._front = (self._front + 1) % 10
        # Decrease the count of elements:
        self._size -= 1
        return dequeued

    def first(self):
        if self.is_empty():
            raise Empty
        return self._data[self._front]

    def is_empty(self):
        return self._size == 0

    def resize(self, capacity):
        # Double the length of the list:
        old_list = self._data
        self._data = [None] * capacity
        front = self._front
        while old_list[front]:
            self._data.append(old_list[front])
            front = (front + 1) % len(self._data)
        self._front = 0

    def __len__(self):
        return self._size
