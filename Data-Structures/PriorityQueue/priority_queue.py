class PriorityQueue:
    def __init__(self, heap=[]):
        self.__priority_queue = [None]
        self.__priority_queue.extend(heap)

    def get_copy(self):
        return self.__priority_queue[:]

    def get_size(self):
        return len(self.__priority_queue)

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

    def max(self):
        return self.__priority_queue[1]

    def get_max(self):
        max_key = self.__priority_queue[1]
        self.__priority_queue[1] = self.__priority_queue.pop()
        key = self.__priority_queue[1]
        self.sink_down(key)
        return max_key

    def sink_down(self, key):
        """ Sink down a given key in order to maintain heap-order """
        key_index = self.__priority_queue.index(key)
        size = self.get_size()
        if key_index * 2 >= size:
            return
        left_child_index = key_index * 2
        left_child = self.__priority_queue[left_child_index]
        right_child_index = (2 * key_index) + 1
        right_child = self.__priority_queue[right_child_index]

        if key > left_child and key > right_child:
            return
        elif not left_child and not right_child:
            return

        if left_child > right_child:
                self.__priority_queue[key_index] = left_child
                self.__priority_queue[left_child_index] = key
                self.sink_down(key)
        elif right_child > left_child:
                self.__priority_queue[key_index] = right_child
                self.__priority_queue[right_child_index] = key
                self.sink_down(key)

    def __str__(self):
        return str(self.__priority_queue)
