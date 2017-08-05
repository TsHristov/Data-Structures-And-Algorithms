#pragma once
#include "node.h"

template<class T>
class Iterator
{
private:
  Node<T> * start;
  Node<T> * end;
  bool reverse;

public:
  Iterator(Node<T> * start, Node<T> * end, bool reverse=false)
  {
    this->start = start;
    this->end   = end;
    this->reverse = reverse;
  }

public:
  bool End() const {return start == end;}
  void Next()
  {
    if (!reverse) start = start->GetNext();
    else if(reverse) end = end->GetPrevious();
  }
  T& Get() const
  {
    if(!reverse) return start->GetData();
    else if(reverse) return end->GetData();
  }
};
