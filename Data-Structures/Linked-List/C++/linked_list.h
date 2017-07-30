#pragma once
#include "node.h"
#include "exceptions.h"
#include "iterator.h"

template<class T>
class LinkedList
{
private:
  Node<T> * first;
  Node<T> * last;
  size_t size;

public:
  LinkedList() { Initialize(); };
  ~LinkedList();
  LinkedList(const LinkedList&);
  LinkedList& operator=(const LinkedList&);

public:
  void PushFront(const T&);
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
  T PopFront();
  size_t GetSize() const { return size; }

public:
  bool operator==(const LinkedList& other) const
  {
    if(this==&other) return true;
    if(size != other.size) return false;
    // Traverse the two linked list and check
    // whether they have the same elements:
    Iterator<T> i = this->ForwardIterator();
    Iterator<T> j = other.ForwardIterator();
    for(; !i.End() && !j.End(); i.Next(), j.Next() )
      if(i.Get() != j.Get()) return false;
    return true;
  }
  bool operator!=(const LinkedList& other) const { return !(*this==other); }

public:
  Iterator<T> ForwardIterator() const { return Iterator<T>(this->first); }

private:
  void Initialize();
  void Free();
  void CopyFrom(const LinkedList&);
};


template<class T>
void LinkedList<T>::Initialize()
{
  first = NULL;
  last  = NULL;
  size  = 0;
}

template<class T>
void LinkedList<T>::Free()
{
  Node<T> * next    = first;
  Node<T> * current = first;
  while(next)
  {
    current = next;
    next    = current->GetNext();
    delete current;
  }
}

template<class T>
void LinkedList<T>::CopyFrom(const LinkedList& other)
{
  Node<T> * temp = other.first;
  T data;
  while(temp)
  {
    data = temp->GetData();
    temp = temp->GetNext();
    PushBack(data);
  }
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList& other)
{
    Initialize();
    CopyFrom(other);
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other)
{
  if(this == &other) return *this;
  else
  {
    Free();
    Initialize();
    CopyFrom(other);
    return *this;
  }
}

template<class T>
LinkedList<T>::~LinkedList()
{
  Free();
}

template<class T>
void LinkedList<T>::PushFront(const T& data)
{
  if(Empty())
  {
    first = new Node<T>(data,NULL);
    last  = first;
  }
  else
  {
    Node<T> * old_first = first;
    first  = new Node<T>(data, old_first);
  }
  ++size;
}

template<class T>
T LinkedList<T>::PopFront()
{
  if(Empty() || !first) throw EmptyList();
  else
  {
    Node<T> * old = first;
    T data = first->GetData();
    first  = first->GetNext();
    // If there are no elements:
    if(first == NULL) last = NULL;
    --size;
    delete old;
    return data;
  }
}

template<class T>
void LinkedList<T>::PushBack(const T& data)
{
  if(Empty())
  {
    first = new Node<T>(data, NULL);
    last  = first;
  }
  else
  {
    Node<T> * old_last = last;
    last = new Node<T>(data, NULL);
    old_last->SetNext(last);
  }
  ++size;
}

template<class T>
void LinkedList<T>::Print() const
{
  std::cout << "List contents: ";
  for(Iterator<T> i = ForwardIterator(); !i.End(); i.Next())
    std::cout << "|" << i.Get() << "|->";
  std::cout << "NULL\n";
}
