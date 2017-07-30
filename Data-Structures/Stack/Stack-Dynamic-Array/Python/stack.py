class EmptyStack(Exception):
    pass


class StackIterator:
    """Iterates over the stack starting from top to bottom"""

    def __init__(self, stack=[]):
        self.__stack = stack
        self.__current = len(stack)

    def __iter__(self):
        return self

    def __next__(self):
        self.__current -= 1
        if self.__current < 0:
            raise StopIteration
        else:
            return self.__stack[self.__current]


class Stack:
    def __init__(self):
        self.__stack = []

    def push(self, value):
        self.__stack.append(value)

    def pop(self):
        if self.is_empty():
            raise EmptyStack("Stack is empty")
        return self.__stack.pop()

    def top(self):
        if self.is_empty():
            raise EmptyStack("Stack is empty")
        return self.__stack[-1]

    def is_empty(self):
        return len(self.__stack) == 0

    def __eq__(self, other):
        if type(other) is type(self):
            return self.__dict__ == other.__dict__
        return False

    def __ne__(self, other):
        return not self.__eq__(other)

    def __iter__(self):
        return StackIterator(self.__stack)

    def __len__(self):
        return len(self.__stack)
