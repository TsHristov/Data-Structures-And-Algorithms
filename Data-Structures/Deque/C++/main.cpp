#include "deque.h"

void Test_InsertFirst()
{
  std::cout << "can insert an element at the beginning...";
  Deque<int> * deque = new Deque<int>;
  deque->InsertFirst(1);
  deque->InsertFirst(2);
  bool condition = deque->First() == 2;
  std::cout << (condition ? "OK\n" : "NOK\n");
  delete deque;
}

void Test_InsertLast()
{
  std::cout << "can insert an element at the end...";
  Deque<int> * deque = new Deque<int>;
  deque->InsertLast(1);
  deque->InsertLast(2);
  bool condition = deque->Last() == 2;
  std::cout << (condition ? "OK\n" : "NOK\n");
  delete deque;
}

int main()
{
  std::cout << "Class Deque:\n";
  Test_InsertFirst();
  Test_InsertLast();
  return 0;
}
