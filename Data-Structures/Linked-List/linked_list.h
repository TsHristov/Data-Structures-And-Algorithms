#pragma once
#include "node.h"
#include "exceptions.h"

template<class T>
class LinkedList
{
private:
  Node<T> * first;
  Node<T> * last;
  size_t size;

public:
  LinkedList(): first(NULL), last(first), size(0) {};
  ~LinkedList() { if(first) delete first; }
  // LinkedList(const LinkedList&);
  // LinkedList& operator=(const LinkedList&);

public:
  void PushFront(const T&);
  T PopFront();
  void PushBack(const T&);
  bool Empty() const { return size == 0; }
  void Print() const;
  T First() const
  {
    if(Empty()) throw EmptyList();
    else return first->GetData();
  }
  T Last()  const
  {
    if(Empty()) throw EmptyList();
    else return last->GetData();
  }
  size_t GetSize() const { return size; }
};

template<class T>
void LinkedList<T>::PushFront(const T& data)
{
  if(!Empty())
  {
    Node<T> * old_first = first;
    first  = new Node<T>(data, old_first);
  }
  else
  {
    first = new Node<T>(data,NULL);
    last  = first;
  }
  ++size;
}

template<class T>
T LinkedList<T>::PopFront()
{
  if(Empty())
  {
    throw EmptyList();
  }
  T data = first->GetData();
  Node<T> * next = first->GetNext();
  // delete first;
  --size;
  first = next;
  return data;
}

template<class T>
void LinkedList<T>::PushBack(const T& data)
{
  if(!Empty())
  {
    Node<T> * old_last = last;
    last = new Node<T>(data, NULL);
    old_last->SetNext(last);
  }
  else
  {
    first = new Node<T>(data, NULL);
    last  = first;
  }
  ++size;
}


template<class T>
void LinkedList<T>::Print() const
{

}
