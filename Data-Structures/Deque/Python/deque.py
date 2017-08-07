import sys
sys.path.insert(0, '../../Doubly-Linked-List/Python')
from doubly_linked_list import Empty, DoublyLinkedList


class Deque(DoublyLinkedList):

    def delete_first(self):
        """Remove and return the first element of the deque."""
        if self.is_empty():
            raise Empty
        return self.delete_node(self._header._next)

    def delete_last(self):
        """Remove and return the last element of the deque."""
        if self.is_empty():
            raise Empty
        return self.delete_node(self._trailer._previous)
