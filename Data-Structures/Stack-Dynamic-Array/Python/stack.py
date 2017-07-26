class EmptyStack(Exception):
    pass

class Stack:
    def __init__(self):
        self._stack = []

    def push(self, value):
        self._stack.append(value)

    def pop(self):
        if self.is_empty():
            raise EmptyStack("Stack is empty")
        else:
            return self._stack.pop()

    def top(self):
        if self.is_empty():
            raise EmptyStack("Stack is empty")
        else:
            return self._stack[-1]

    def is_empty(self):
        return len(self._stack) == 0

    def len(self):
        return len(self._stack)
