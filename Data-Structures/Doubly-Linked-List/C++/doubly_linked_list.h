#pragma once
#include "exceptions.h"
#include "node.h"

template<class T>
class DoublyLinkedList
{
private:
  // Sentinel nodes, mark the head
  // and the tail of the list
  Node<T> * header;
  Node<T> * trailer;
  size_t size;

public:
  DoublyLinkedList()
  {
    header  = new Node<T>();
    trailer = new Node<T>();
    header->SetNext(trailer);
    trailer->SetPrevious(header);
    size = 0;
  }
  ~DoublyLinkedList()
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

public:
  void InsertBetween(const T&, Node<T> *, Node<T> *);
  void InsertFirst(const T&);
  void InsertLast(const T&);
  T DeleteNode(Node<T> *);
  T First() const;
  T Last() const;
  bool Empty() const { return size == 0; }
  size_t GetSize() const { return size; }
};

template<class T>
void DoublyLinkedList<T>::InsertBetween(const T& data, Node<T> * predecessor, Node<T> *  successor)
{
  if(Empty()) throw EmptyList();
  else
  {
    Node<T> * new_node = new Node<T>(data, predecessor, successor);
    predecessor->SetNext(new_node);
    successor->SetPrevious(new_node);
    ++size;
  }
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
  Node<T> * node = new Node<T>(data, NULL, NULL);
  Node<T> * next = header->GetNext();
  header->SetNext(node);
  node->SetNext(next);
  ++size;
}


template<class T>
void DoublyLinkedList<T>::InsertLast(const T& data)
{
  Node<T> * node = new Node<T>(data, NULL, NULL);
  Node<T> * previous = trailer->GetPrevious();
  node->SetPrevious(previous);
  node->SetNext(trailer);
  ++size;
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
