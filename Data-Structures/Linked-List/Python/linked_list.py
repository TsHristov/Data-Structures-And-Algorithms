import node


class EmptyLinkedList(Exception):
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
            raise EmptyLinkedList
        else:
            data = self._first.data
            self._first = self._first.next
            self._size -= 1
            return data

    def first(self):
        if self.is_empty():
            raise EmptyLinkedList
        else:
            return self._first.data

    def last(self):
        if self.is_empty():
            raise EmptyLinkedList
        else:
            return self._last.data

    def size(self):
        return self._size
        
    def is_empty(self):
        return self._size == 0
