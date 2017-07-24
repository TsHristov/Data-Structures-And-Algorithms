#pragma once
template<class T>

class Node
{
private:
  T data;
  Node * next;

public:
  Node(const T& data, Node * next=NULL)
  {
    this->data = data;
    this->next = next;
  }

  ~Node(){ if(next) delete next; }

public:
  void SetData(const T& data) { this->data = data; }
  T GetData() { return data; }
  void SetNext(Node * next) { this->next = next; }
  Node * GetNext() { return next; }
};
