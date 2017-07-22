## Dynamic Array API:
* `int Index(T value) const` - returns the index of a given element
* `int Count(T value) const` - returns count of occurences of an element in the array
* `void Reverse()` - reverses the array in place;
  - `O(n)`
* `void Append(T value)` - appends an element to the end of the array
  - `O(1)`
* `bool IsEmpty() const`
  - `O(1)`
* `DynamicArray& Expand(DynamicArray& other)` - expands the given array with an instance of another one
* `T Pop()` - remove and return last element
* `T Pop(size_t index)` - remove and return element at given index, throws and exception if index is out of bounds
* `T& First() const` - return first element of the array
* `T& Last() const` - return last element of the array
* `size_t GetSize() const` - return number of elements in the array
* `size_t GetCapacity() const` - return the maximum current capacity of the array
* `T& operator[](size_t index)` - returns a reference to an element from the array using [], if index out of bounds throws an exception
* `bool operator==(const DynamicArray&)` - checks whether two different instances are equal (if they have same lenght and elements)
* `bool operator!=(const DynamicArray&)` - checks whether two different instances are not equal
* `DynamicArray& operator+=(DynamicArray&)` - expands current instance with another one
* `const DynamicArray operator+(DynamicArray& other) const` - returns new instance which is result of the concatenation of the current and other
* `void Resize(size_t)` - resizes the array. Doubles the capacity if size == capacity and halves it if size == capacity/4, thus resulting in amortized constant time of appending and removing an element from the end
