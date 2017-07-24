#pragma once
#include <iostream>

template<class T>
class Node
{
private:
  T data;
  Node<T> * next;

public:
  Node(const T& data, Node * next=NULL)
  {
    this->data = data;
    this->next = next;
  }

public:
  void SetData(const T& data) { this->data = data; }
  T GetData() const { return data; }
  void SetNext(Node * next) { this->next = next; }
  Node * GetNext() { if(next) return next; else return NULL; }
};
