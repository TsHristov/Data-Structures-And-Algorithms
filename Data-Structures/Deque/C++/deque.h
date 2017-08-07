#pragma once
#include "../../Doubly-Linked-List/C++/doubly_linked_list.h"

template<class T>
class Deque: public DoublyLinkedList<T>
{
public:
  T& DeleteFirst();
  T& DeleteLast();
};
