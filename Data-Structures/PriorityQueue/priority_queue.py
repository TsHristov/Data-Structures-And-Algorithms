class PriorityQueue:
    def __init__(self, heap=[]):
        self.__priority_queue = [None]
        self.__priority_queue.extend(heap)

    def get_copy(self):
        return self.__priority_queue[:]

    def insert(self, key):
        self.__priority_queue.append(key)
        self.swim_up(key)

    def swim_up(self, key, parent=None):
        key_index = self.__priority_queue.index(key)
        parent_index = key_index // 2
        parent = self.__priority_queue[parent_index]
        if parent > key:
            return
        self.__priority_queue[parent_index] = key
        self.__priority_queue[key_index] = parent
        self.swim_up(key, parent)

    def __str__(self):
        return str(self.__priority_queue)
