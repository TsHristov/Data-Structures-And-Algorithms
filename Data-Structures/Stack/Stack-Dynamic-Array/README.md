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

# Additional methods:
* `operator==, operator!=` - compares two stack instances
  - `O(n)` - where n is the size of the stack
* `ReverseIterator<T> GetIterator() const` - gets Iterator object over the stack, iterates starting from the top of the stack to the bottom
