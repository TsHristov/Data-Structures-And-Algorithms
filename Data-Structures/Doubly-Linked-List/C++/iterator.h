#pragma once
#include "node.h"

template<class T>
class Iterator
{
private:
  Node<T> * start;
  Node<T> * end;

public:
  Iterator(Node<T> * start, Node<T> * end)
  {
    this->start = start;
    this->end   = end;
  }

public:
  bool End() const {return start == end;}
  void Next() {start = start->GetNext();}
  T& Get() const {return start->GetData();}
};
