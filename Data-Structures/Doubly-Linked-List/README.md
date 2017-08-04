# Doubly Linked List API: C++ / Python
* `void InsertBetween(const T&, Node<T>*, Node<T>*)` / `insert_between(data, predecessor, successor)` - constructs and inserts a node between other two
  - `O(1)`
* `void InsertFirst(const T&)`/ `insert_first(data)` - creates and inserts a node at the beginning of the list
  - `O(1)`
* `void InsertLast(const T&)`/ `insert_last(data)` - creates and inserts a node at the end of the list
  - `O(1)`
* `T DeleteNode(Node<T> *)` / `delete_node(node)` - deletes a given node
  - `O(1)`
* `T First() const`/ `first()` - retrieves the first node from the list  without removing it
  - `O(1)`
* `T Last() const`/ `last()` - retrieves the last node from the
list without removing it
  - `O(1)`
* `bool Empty() const` / `is_empty()` - checks whether the list is empty
  - `O(1)`
* `size_t GetSize() const` / `__len__` - returns the size of the list
  - `O(1)`
