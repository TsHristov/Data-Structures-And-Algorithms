import node
import iterator


class Empty(Exception):
    pass


class DoublyLinkedList:
    def __init__(self):
        self._header = node.Node()
        self._trailer = node.Node()
        self._header._next = self._trailer
        self._trailer._previous = self._header
        self._size = 0

    def insert_between(self, data, predecessor, successor):
        new_node = node.Node(data, predecessor, successor)
        predecessor._next = new_node
        successor._previous = new_node
        self._size += 1
        return new_node

    def delete_node(self, node):
        if self.is_empty():
            raise Empty
        predecessor = node._previous
        successor = node._next
        predecessor._next = successor
        successor._previous = predecessor
        data = node._data
        node._data = node._previous = node._next = None
        self._size -= 1
        return data

    def insert_first(self, data):
        self.insert_between(data, self._header, self._header._next)

    def insert_last(self, data):
        self.insert_between(data, self._trailer._previous, self._trailer)

    def first(self):
        if self.is_empty():
            raise Empty
        return self._header._next._data

    def last(self):
        if self.is_empty():
            raise Empty
        return self._trailer._previous._data

    def is_empty(self):
        return self._size == 0

    def __iter__(self):
        first = self._header._next
        return iterator.Iterator(first, None)

    def __reversed__(self):
        last = self._trailer._previous
        return iterator.Iterator(None, last)

    def __len__(self):
        return self._size
