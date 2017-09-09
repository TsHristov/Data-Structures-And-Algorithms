# Queue API: C++ / Python
* / `enqueue(data)` - add an element to the tail of the queue
  - `O(1)` - amortized, because of the resizing of the underlying array
* / `dequeue()` - remove and return the head of the queue
  - `O(1)` - amortized, because of the resizing of the underlying array
* / `first()` - returns the head of the queue
  - `O(1)`
* / `is_empty()` - checks if the queue is empty
  - `O(1)`
* / `__len__` - returns the size of the queue
  - `O(1)`
