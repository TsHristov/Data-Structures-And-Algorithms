#include "../../../Linked-List/C++/linked_list.h"

template<class T>
class Queue: public LinkedList<T>
{
public:
  Iterator<T> GetIterator() const { return this->ForwardIterator(); }

public:
  void Enqueue(const T& data) { return this->PushBack(data); }
  T Dequeue() { return this->PopFront(); }
};
