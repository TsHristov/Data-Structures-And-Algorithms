#pragma once
#include <iostream>

template<class T>
class Node
{
private:
  T data;
  Node<T> * next;
  Node<T> * previous;

public:
  Node(): next(NULL), previous(NULL) {}
  Node(const T& d, Node<T> * n, Node<T> * p):
    data(d),
    next(n),
    previous(p) {}

public:
  T GetData() const { return data; }
  Node<T> * GetPrevious() const { return this->previous; }
  Node<T> * GetNext() const { return this->next; }
  void SetNext(Node<T> * other) { this->next = other; }
  void SetPrevious(Node<T> * other) { this->previous = other; }
};
