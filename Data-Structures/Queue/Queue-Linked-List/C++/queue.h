#include "../../../Linked-List/C++/linked_list.h"

template<class T>
class Queue
{
private:
  LinkedList<T> queue;

public:
  Queue();
  Queue(const Queue&);
  Queue& operator=(const Queue&);

public:
  void Enqueue(const T& data);
  T& Dequeue();
  bool Empty() const { return queue.Empty(); }
  T First() const { return queue.First(); }
  T Last() const { return queue.Last(); }
  size_t GetSize() const { return queue.GetSize(); }
};
