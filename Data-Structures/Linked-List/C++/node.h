#pragma once
#include <iostream>

template<class T>
class Node
{
private:
  T data;
  Node * next;

public:
  Node(const T& data, Node * next)
  {
    this->data = data;
    this->next = next;
  }

public:
  T GetData() const { return data; }
  void SetData(const T& data) { this->data = data; }
  void SetNext(Node * next)   { this->next = next; }
  Node * GetNext() { if(next) return next; else return NULL; }
};
