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
  Node(const T& data, Node<T> * previous, Node<T> * next)
  {
    this->data = data;
    this->previous = previous;
    this->next = next;
  }

public:
  T& GetData() { return data; }
  Node<T> * GetPrevious() const { return this->previous; }
  Node<T> * GetNext() const { return this->next; }
  void SetNext(Node<T> * other) { this->next = other; }
  void SetPrevious(Node<T> * other) { this->previous = other; }

public:
  bool IsHeader() const { return this->previous == NULL; }
  bool IsTrailer() const { return this->next == NULL; }
};
