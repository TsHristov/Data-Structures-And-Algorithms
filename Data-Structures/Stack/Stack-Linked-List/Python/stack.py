import sys
sys.path.insert(0, '../../../Linked-List/Python')
import linked_list


class EmptyStack(Exception):
    pass


class StackIterator(linked_list.ListIterator):
    """Iterates over the stack starting from top to bottom"""
    pass


class Stack:
    def __init__(self):
        self._stack = linked_list.LinkedList()

    def push(self, value):
        self._stack.push_front(value)

    def pop(self):
        if self.is_empty():
            raise EmptyStack("Stack is empty")
        else:
            return self._stack.pop_front()

    def top(self):
        if self.is_empty():
            raise EmptyStack("Stack is empty")
        else:
            return self._stack.first()

    def is_empty(self):
        return self._stack.is_empty()

    def __eq__(self, other):
        raise NotImplemented

    def __ne__(self, other):
        raise NotImplemented

    def __iter__(self):
        return StackIterator(self._stack._first)

    def __len__(self):
        return len(self._stack)
