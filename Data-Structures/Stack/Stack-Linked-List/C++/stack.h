// Applies the Adapter Pattern - contains LinkedList instance
#include "../../Linked-List/linked_list.h"

template<class T>
class Stack
{
private:
  LinkedList<T> stack;

public:
  Stack() {};
  Stack(const Stack& other): stack(other.stack) {};
  Stack& operator=(const Stack& other)
  {
    if(this == &other) return *this;
    stack = other.stack;
    return *this;
   };
  bool operator==(const Stack& other) const { return stack == other.stack; };
  bool operator!=(const Stack& other) const { return stack != other.stack; };

public:
  // Traverses the stack, starting from top to bottom:
  Iterator<T> GetIterator() const { return stack.ForwardIterator(); }

public:
  void Push(const T& data) { stack.PushFront(data); }
  T Pop() { return stack.PopFront(); }
  T Top() const { return stack.First(); }
  bool Empty() const { return stack.Empty(); }
  void Print() const { stack.Print(); }
  size_t GetSize() const { return stack.GetSize();}
};
