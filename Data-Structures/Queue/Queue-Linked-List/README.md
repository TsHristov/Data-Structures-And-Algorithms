# Queue API: C++ / Python
* `void Enqueue(const T& data)` / `enqueue(data)` - add an element to the tail of the queue
  - `O(1)`
* `T Dequeue()` / `dequeue()` - remove and return the head of the queue
  - `O(1)`
* `T First() const` / `first()` - returns the head of the queue
  - `O(1)`
* `T Last() const` / `last()` - returns the tail of the queue
  - `O(1)`
* `bool Empty() const` / `is_empty()` - checks if the queue is empty
  - `O(1)`
* `size_t GetSize() const` / `__len__` - returns the size of the queue
  - `O(1)`
