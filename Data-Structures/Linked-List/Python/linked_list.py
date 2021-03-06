import node


class Iterator:
    def __init__(self, start):
        self._current = start

    def __iter__(self):
        return self

    def __next__(self):
        if not self._current:
            raise StopIteration
        else:
            current = self._current
            self._current = self._current.next
            return current


class Empty(Exception):
    pass


class LinkedList:
    def __init__(self):
        self._first = None
        self._last  = self._first
        self._size  = 0

    def push_back(self, data):
        if self.is_empty():
            self._first = node.Node(data)
            self._last = self._first
            self._size += 1
        else:
            old_last = self._last
            self._last = node.Node(data)
            old_last.next = self._last
            self._size += 1

    def push_front(self, data):
        if self.is_empty():
            self._first = node.Node(data)
            self._last  = self._first
            self._size += 1
        else:
            old_first = self._first
            self._first = node.Node(data)
            self._first.next = old_first
            self._size += 1

    def pop_front(self):
        if self.is_empty():
            raise Empty
        else:
            data = self._first.data
            self._first = self._first.next
            self._size -= 1
            return data

    def first(self):
        if self.is_empty():
            raise Empty
        else:
            return self._first.data

    def last(self):
        if self.is_empty():
            raise Empty
        else:
            return self._last.data

    def is_empty(self):
        return self._size == 0

    def __eq__(self, other):
        if not type(other) is type(self):
            return False
        if len(self) != len(other):
            return False
        for node_self, node_other in zip(self, other):
            if node_self != node_other:
                return False
        return True

    def __ne__(self, other):
        return not self.__eq__(other)

    def __iter__(self):
        return Iterator(self._first)

    def __len__(self):
        return self._size
