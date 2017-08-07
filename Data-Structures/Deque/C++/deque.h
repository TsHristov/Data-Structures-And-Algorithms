#pragma once
#include "../../Doubly-Linked-List/C++/doubly_linked_list.h"

template<class T>
class Deque: public DoublyLinkedList<T>
{
public:
  T DeleteFirst();
  T DeleteLast();
};

template<class T>
T Deque<T>::DeleteFirst()
{
  Node<T> * first = this->header->GetNext();
  return this->DeleteNode(first);
}

template<class T>
T Deque<T>::DeleteLast()
{
  Node<T> * last = this->trailer->GetPrevious();
  return this->DeleteNode(last);
}
