#include "../Dynamic-Array/dynamic_array.h"

template<class T>
class Stack
{
private:
  DynamicArray<T> stack;

public:
  Stack();
  ~Stack();
  Stack(const Stack&);
  Stack& operator=(const Stack&);

public:
  void Push(const T& data);
  T& Pop();
  bool Empty() const;

private:
  void Free();
  void CopyFrom(const Stack&);
};
