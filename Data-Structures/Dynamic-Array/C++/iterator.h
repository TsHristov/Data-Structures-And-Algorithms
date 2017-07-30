#pragma once
#include "exceptions.h"

template<class T>
class ForwardIterator
{
private:
  T * start;
  size_t index;
  size_t size;

public:
  ForwardIterator(T * start, size_t size)
  {
    this->start = start;
    this->size  = size;
    index = 0;
  }
  void Next()
  {
    if(End()) throw EmptyArray();
    else ++index;
  }
  T& Get() const
  {
    if(End()) throw EmptyArray();
    else return start[index];
  }
  bool End() const { return index >= size; }
};

template<class T>
class ReverseIterator
{
private:
  T * start;
  int index;

public:
  ReverseIterator(T * start, size_t size)
  {
    this->start = start;
    this->index = size-1;
  }
  void Next()
  {
    if(End()) throw EmptyArray();
    else --index;
  }
  T& Get() const
  {
    if(End()) throw EmptyArray();
    else return start[index];
  }
  bool End() const { return index < 0; }
};
