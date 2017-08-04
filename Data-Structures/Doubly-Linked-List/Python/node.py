class Node:
    """Represents a doubly linked node."""
    __slots__ = '_data', '_previous', '_next'

    def __init__(self, _data=None, _previous=None, _next=None):
        self._data = _data
        self._previous = _previous
        self._next = _next

    def is_trailer(self):
        return self._data is self._next is None

    def is_header(self):
        return self._data is self._previous is None
