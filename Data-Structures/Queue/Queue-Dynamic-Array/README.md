# Queue API: C++ / Python
* `void Enqueue(const T&)`/`enqueue(data)` - add an element to the tail of the queue
  - `O(1)` - amortized, because of the resizing of the underlying array
* `T Dequeue()`/`dequeue()` - remove and return the head of the queue
  - `O(1)` - amortized, because of the resizing of the underlying array
* `T First()`/`first()` - returns the head of the queue
  - `O(1)`
* `bool Empty()`/`is_empty()` - checks if the queue is empty
  - `O(1)`
* `size_t GetSize()`/`__len__` - returns the size of the queue
  - `O(1)`
