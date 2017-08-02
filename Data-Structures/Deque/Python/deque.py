import sys
sys.path.insert(0, '../../Doubly-Linked-List/Python')
import doubly_linked_list


class EmptyDeque(Exception):
    pass


class Deque(doubly_linked_list.DoublyLinkedList):
    def insert_first(self, data):
        """Add an element to the front of the deque."""
        self.insert_between(data, self._header, self._header._next)

    def insert_last(self, data):
        """Add an element to the back of the deque."""
        self.insert_between(data, self._trailer._previous, self._trailer)

    def delete_first(self):
        """Remove and return the first element of the deque."""
        if self.is_empty():
            raise EmptyDeque
        return self.delete_node(self._header._next)

    def delete_last(self):
        """Remove and return the last element of the deque."""
        if self.is_empty():
            raise EmptyDeque
        return self.delete_node(self._trailer._previous)

    def first(self):
        """Return the first element of the deque."""
        if self.is_empty():
            raise EmptyDeque
        return self._header._next._data

    def last(self):
        """Return the last element of the deque."""
        if self.is_empty():
            raise EmptyDeque
        return self._trailer._previous._data
