#pragma once
#include "node.h"

template<class T>
class Iterator
{
private:
  Node<T> * start;
  bool reverse;

public:
  Iterator(Node<T> * start, bool reverse=false)
  {
    this->start = start;
    this->reverse = reverse;
  }

public:
  bool End() const
  {
    if(!reverse) return start->GetNext() == NULL;
    else return start->GetPrevious() == NULL;
  }
  void Next()
  {
    if (!reverse) start = start->GetNext();
    else start = start->GetPrevious();
  }
  T& Get() const
  {
    return start->GetData();
  }
};
