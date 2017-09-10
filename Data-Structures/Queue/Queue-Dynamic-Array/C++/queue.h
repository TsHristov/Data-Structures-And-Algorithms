#include "../../../Dynamic-Array/C++/dynamic_array.h"
#include "exceptions.h"

template<class T>
class Queue
{
private:
  size_t front; // index of the first element in the queue
  size_t size;  // count of elements in the queue
  DynamicArray<T> array;

public:
  Queue():front(0), size(0), array() {}
  Queue(const Queue&);
  Queue& operator=(const Queue&);

public:
  void Enqueue(const T& data);
  T Dequeue();
  T First()
  {
    if(Empty()) throw EmptyQueue();
    return array[front];
  }
  bool Empty() const { return size == 0; }
  size_t GetSize() const { return size; }

private:
  void Resize(size_t capacity);
};

template<class T>
void Queue<T>::Enqueue(const T& data)
{
  size_t array_capacity = array.GetCapacity();
  if(size == array_capacity) Resize(2 * array_capacity);
  size_t available_position = (front + size) % array.GetCapacity();
  array[available_position] = data;
  size += 1;
}

template<class T>
T Queue<T>::Dequeue()
{
  if(Empty()) throw EmptyQueue();
  size_t array_capacity = array.GetCapacity();
  T element = array[front];
  front = (front + 1) % array_capacity;
  size -= 1;
  if(size < array_capacity / 4) Resize(array_capacity / 2);
  return element;
}

template<class T>
void Queue<T>::Resize(size_t capacity)
{
  DynamicArray<T> old = array;
  array.Resize(capacity);
  size_t front = this->front;
  for(size_t i = 0; i < size; i++)
  {
    array[i] = old[front];
    front = (front + 1) % old.GetCapacity();
  }
  this->front = 0;
}
