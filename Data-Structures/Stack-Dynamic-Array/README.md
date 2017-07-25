# Stack API:
* `void Push(const T& data)` - push an element onto the stack
  - `O(1)` - amortized (because of the dynamic array used)
* `T Pop()` - remove and retrieve top element of the stack
  - `O(1)` - amortized (because of the dynamic array used)
* `T& Top() const` - returns the top element, without removing it from the stack
  - `O(1)`
* `bool Empty() const` - checks whether the stack is empty
  - `O(1)`
* `size_t GetSize() const`  - returns the size of the stack
  - `O(1)`
