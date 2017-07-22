## Dynamic Array API:
* `int Index(T value) const` - returns the index of the first occurence of a given element
  - `O(n)`
* `int Count(T value) const` - returns count of occurences of an element in the array
  - `O(n)`
* `void Reverse()` - reverses the array in-place;
  - `O(n)`
* `void Insert(size_t index, T value)` - inserts an element at given index
  - `O(n - index + 1)` - amortized, has to shift all elements to the right of index to make space for the new element
* `void Append(T value)` - appends an element to the end of the array
  - `O(1)`
* `bool IsEmpty() const` - checks whether array is empty
  - `O(1)`
* `DynamicArray& Expand(DynamicArray& other)` - expands the given array with an instance of another one
* `T Pop()` - remove and return last element
  - `O(1)`
* `T Pop(size_t index)` - remove and return element at given index, throws and exception if index is out of bounds
  - `O(n - index)` - amortized, has to shift all elements to the left after the element has been removed
* `T& First() const` - return first element of the array
  - `O(1)`
* `T& Last() const` - return last element of the array
  - `O(1)`
* `size_t GetSize() const` - return number of elements in the array
  - `O(1)`
* `size_t GetCapacity() const` - return the maximum current capacity of the array
  - `O(1)`
* `T& operator[](size_t index)` - returns a reference to an element from the array using [], if index out of bounds throws an exception
  - `O(1)`
* `bool operator==(const DynamicArray&)` - checks whether two different instances are equal (if they have same lenght and elements)
* `bool operator!=(const DynamicArray&)` - checks whether two different instances are not equal
* `DynamicArray& operator+=(DynamicArray&)` - expands current instance with another one
  - `O(m)` - m - size of the other array
* `const DynamicArray operator+(DynamicArray& other) const` - returns new instance which is result of the concatenation of the current and other
* `void Resize(size_t)` - resizes the array. Doubles the capacity if size == capacity and halves it if size == capacity/4, thus resulting in amortized constant time of appending and removing an element from the end
