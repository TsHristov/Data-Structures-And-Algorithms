class Iterator:
    def __init__(self, start):
        self._start = start

    def __iter__(self):
        return self

    def __next__(self):
        if self._start.is_trailer():
            raise StopIteration
        else:
            data = self._start._data
            self._start = self._start._next
            return data
