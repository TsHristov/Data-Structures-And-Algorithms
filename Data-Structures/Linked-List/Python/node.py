class Node:
    def __init__(self, data=None):
        self.data = data
        self.next = None

    def __repr__(self):
        return str(self)
        
    def __str__(self):
        return str(self.data)
