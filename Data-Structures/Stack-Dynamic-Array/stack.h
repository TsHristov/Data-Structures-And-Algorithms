#include "../Dynamic-Array/dynamic_array.h"

template<class T>
class Stack
{
private:
  DynamicArray<T> stack;

public:
  Stack() {};
  Stack(const Stack&);
  Stack& operator=(const Stack&);

public:
  void Push(const T& data) { stack.Append(data); }
  T Pop() { return stack.Pop(); }
  T& Top() const { return stack.Last(); }
  bool Empty() const { return stack.Empty(); }
  void Print() const { stack.Print(); }
  size_t GetSize() const { return stack.GetSize();}

private:
  void CopyFrom(const Stack&);
};
