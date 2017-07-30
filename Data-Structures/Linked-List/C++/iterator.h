#pragma once
#include "node.h"
#include "exceptions.h"

template<class T>
class Iterator
{
private:
  Node<T> * start;
  Node<T> * current;

public:
  Iterator(Node<T> * start) { this->start = this->current = start; }
  void Next()
  {
    if(current) current = current->GetNext();
    else throw EmptyList();
  }
  T Get() const
  {
    if(current) return current->GetData();
    else throw EmptyList();
  }
  void Set(const T& data)
  {
    if(current) current->SetData(data);
    else throw EmptyList();
  }
  bool End() const { return current == NULL; }
};
