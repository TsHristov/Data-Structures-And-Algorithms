# Priority Queue implementation using Heap
# Properties:
# Insert: logN
# Remove maximum: logN

class PriorityQueue:
    """Priority Queue implementation.

    Priority Queue implementation using a heap to
    store the collection.

    Attributes:
        __priority_queue: A list, with first element not used.
        (This is in order to be able to perform index arithmetics)
    """
    def __init__(self, heap=[]):
        self.__priority_queue = [None]
        self.__priority_queue.extend(heap)

    def get_copy(self):
        return self.__priority_queue[:]

    def get_size(self):
        return len(self.__priority_queue)

    def is_empty(self):
        return self.get_size() == 0

    def insert(self, key):
        """ Insert an arbitrary key in the collection """
        self.__priority_queue.append(key)
        self.swim_up(key)

    def max(self):
        return self.__priority_queue[1]

    def get_max(self):
        """ Return and remove the max element in the queue """
        max_key = self.__priority_queue[1]
        self.__priority_queue[1] = self.__priority_queue.pop()
        key = self.__priority_queue[1]
        self.sink_down(key)
        return max_key

    # Heap operations:
    def swim_up(self, key, parent=None):
        """ Swim up a given key in order to maintain heap-order """
        key_index = self.__priority_queue.index(key)
        parent_index = key_index // 2
        parent = self.__priority_queue[parent_index]
        if parent > key:
            return
        self.__priority_queue[parent_index] = key
        self.__priority_queue[key_index] = parent
        self.swim_up(key, parent)

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
