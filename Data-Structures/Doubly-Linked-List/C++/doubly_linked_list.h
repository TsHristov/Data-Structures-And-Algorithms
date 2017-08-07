#pragma once
#include "exceptions.h"
#include "node.h"
#include "iterator.h"

template<class T>
class DoublyLinkedList
{
protected:
  // Sentinel nodes, mark the head
  // and the tail of the list
  Node<T> * header;
  Node<T> * trailer;
  size_t size;

public:
  DoublyLinkedList() {Initialize();}
  DoublyLinkedList(const DoublyLinkedList&);
  ~DoublyLinkedList() {Free();}
  DoublyLinkedList& operator=(const DoublyLinkedList&);

public:
  bool operator==(const DoublyLinkedList&) const;
  bool operator!=(const DoublyLinkedList&) const;

public:
  Iterator<T> ForwardIterator() const
  {
    Node<T> * start = header->GetNext();
    return Iterator<T>(start);
  }
  Iterator<T> ReverseIterator() const
  {
    Node<T> * end   = trailer->GetPrevious();
    return Iterator<T>(end, true); // reverse = true
  }

public:
  void InsertBetween(const T&, Node<T> *, Node<T> *);
  void InsertFirst(const T&);
  void InsertLast(const T&);
  T DeleteNode(Node<T> *);
  T First() const;
  T Last() const;
  bool Empty() const {return size == 0;}
  size_t GetSize() const {return size;}

private:
  void Initialize();
  DoublyLinkedList& CopyFrom(const DoublyLinkedList&);
  void Free();
};

template<class T>
void DoublyLinkedList<T>::Initialize()
{
  header  = new Node<T>;
  trailer = new Node<T>;
  header->SetNext(trailer);
  trailer->SetPrevious(header);
  size = 0;
}

template<class T>
DoublyLinkedList<T>& DoublyLinkedList<T>::CopyFrom(const DoublyLinkedList& other)
{
  if(this == &other) return *this;
  else
  {
    Iterator<T> i = other.ForwardIterator();
    for(; !i.End(); i.Next())
    {
      T data = i.Get();
      this->InsertLast(data);
    }
    return *this;
  }
}

template<class T>
void DoublyLinkedList<T>::Free()
{
  Node<T> * current = header;
  Node<T> * next = header;
  while(next)
  {
    next = current->GetNext();
    delete current;
    current = next;
  }
}

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& other)
{
  Initialize();
  CopyFrom(other);
}

template<class T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList& other)
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
bool DoublyLinkedList<T>::operator==(const DoublyLinkedList& other) const
{
  if(this==&other) return true;
  if(size != other.size) return false;
  else
  {
    Iterator<int> i = this->ForwardIterator();
    Iterator<int> j = other.ForwardIterator();
    for(; !i.End() && !j.End(); i.Next(), j.Next())
    {
      if(i.Get() != j.Get()) return false;
    }
    return true;
  }
}

template<class T>
bool DoublyLinkedList<T>::operator!=(const DoublyLinkedList& other) const
{
  return !(*this==other);
}

template<class T>
void DoublyLinkedList<T>::InsertBetween(const T& data, Node<T> * predecessor, Node<T> *  successor)
{
  Node<T> * new_node = new Node<T>(data, predecessor, successor);
  predecessor->SetNext(new_node);
  successor->SetPrevious(new_node);
  ++size;
}

template<class T>
T DoublyLinkedList<T>::DeleteNode(Node<T> * node)
{
  if(Empty()) throw EmptyList();
  else
  {
    Node<T> * previous = node->GetPrevious();
    Node<T> * next = node->GetNext();
    T data = node->GetData();
    previous->SetNext(next);
    next->SetPrevious(previous);
    delete node;
    node = NULL;
    --size;
    return data;
  }
}

template<class T>
void DoublyLinkedList<T>::InsertFirst(const T& data)
{
  InsertBetween(data, header, header->GetNext());
}

template<class T>
void DoublyLinkedList<T>::InsertLast(const T& data)
{
  InsertBetween(data, trailer->GetPrevious(), trailer);
}

template<class T>
T DoublyLinkedList<T>::First() const
{
  if(Empty()) throw EmptyList();
  else
  {
    Node<T> * node = header->GetNext();
    return node->GetData();
  }
}

template<class T>
T DoublyLinkedList<T>::Last() const
{
  if(Empty()) throw EmptyList();
  else
  {
    Node<T> * node = trailer->GetPrevious();
    return node->GetData();
  }
}
