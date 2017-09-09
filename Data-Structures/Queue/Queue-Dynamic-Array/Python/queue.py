class Empty(Exception):
    pass


class Queue:
    """ Queue implementation using circular array """

    DEFAULT_CAPACITY = 10

    def __init__(self):
        """Create an empty queue."""
        self._data  = [None] * Queue.DEFAULT_CAPACITY
        self._size  = 0
        self._front = 0

    def enqueue(self, data):
        """Add an element to the back of the queue."""
        if self._size == len(self._data):
            self._resize(2 * len(self._data))  # double the size of the array
        availabe_spot = (self._front + self._size) % len(self._data)
        self._data[availabe_spot] = data
        self._size += 1

    def dequeue(self):
        """Remove and return the first element in the queue."""
        if self.is_empty():
            raise Empty
        dequeued = self._data[self._front]
        self._data[self._front] = None
        self._front = (self._front + 1) % len(self._data)
        self._size -= 1
        if self._size < len(self._data) // 4:
            self._resize(len(self._data) // 2)
        return dequeued

    def first(self):
        """Return the first element in the queue."""
        if self.is_empty():
            raise Empty
        return self._data[self._front]

    def is_empty(self):
        """Return True if queue is empty."""
        return self._size == 0

    def _resize(self, capacity):
        """Create new array with size = capacity"""
        old_list = self._data
        self._data = [None] * capacity
        front = self._front
        for i in range(self._size):
            self._data[i] = old_list[front]
            front = (front + 1) % len(self._data)
        self._front = 0

    def __len__(self):
        """Return count of elements in the queue."""
        return self._size
