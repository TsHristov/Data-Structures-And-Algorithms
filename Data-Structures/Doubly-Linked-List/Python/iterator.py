class Iterator:
    def __init__(self, start=None, end=None):
        self._start = start
        self._end = end

    def __iter__(self):
        return self

    def __next__(self):
        if self._start: # Forward direction
            if self._start.is_trailer():
                raise StopIteration
            else:
                data = self._start._data
                self._start = self._start._next
                return data
        if self._end: # Reverse direction
            if self._end.is_header():
                raise StopIteration
            else:
                data = self._end._data
                self._end = self._end._previous
                return data
