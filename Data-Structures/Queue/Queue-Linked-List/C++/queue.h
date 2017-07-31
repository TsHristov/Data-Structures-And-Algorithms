#include "iterator.h"
#include "exceptions.h"
#include "../../../Linked-List/C++/linked_list.h"

template<class T>
class Queue
{
private:
  LinkedList<T> queue;

public:
  Queue(): queue() {};
  Queue(const Queue& other): queue(other.queue) {};
  Queue& operator=(const Queue&);

public:
  bool operator==(const Queue&) const;
  bool operator!=(const Queue&) const;

public:
  QueueIterator<T> Iterator() const {return QueueIterator<T>(queue);};

public:
  void Enqueue(const T& data);
  T Dequeue();
  bool Empty() const {return queue.Empty();}
  T First() const;
  T Last() const;
  size_t GetSize() const {return queue.GetSize();}
};

template<class T>
void Queue<T>::Enqueue(const T& data)
{
  queue.PushBack(data);
}

template<class T>
T Queue<T>::Dequeue()
{
  if(Empty()) throw EmptyQueue();
  return queue.PopFront();
}

template<class T>
T Queue<T>::First() const
{
  if(Empty()) throw EmptyQueue();
  return queue.First();
}

template<class T>
T Queue<T>::Last() const
{
  if(Empty()) throw EmptyQueue();
  return queue.Last();
}
