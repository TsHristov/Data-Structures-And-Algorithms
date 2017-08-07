#include "deque.h"

void Test_DeleteFirst()
{
  std::cout << "can delete an element from the beginning...";
  Deque<int> * deque = new Deque<int>;
  bool condition1 = false;
  try
  {
    deque->DeleteFirst();
  }catch(EmptyList&)
  {
    condition1 = true;
  }
  deque->InsertLast(1);
  deque->InsertLast(2);
  bool condition2 = deque->DeleteFirst() == 1;
  bool condition3 = deque->First() == 2;
  bool condition = condition1 && condition2 && condition3;
  std::cout << (condition ? "OK\n" : "NOK\n");
  delete deque;
}

void Test_DeleteLast()
{
  std::cout << "can delete an element from the end...";
  Deque<int> * deque = new Deque<int>;
  bool condition1 = false;
  try
  {
    deque->DeleteLast();
  }catch(EmptyList&)
  {
    condition1 = true;
  }
  deque->InsertLast(1);
  deque->InsertLast(2);
  bool condition2 = deque->DeleteLast() == 2;
  bool condition3 = deque->Last() == 1;
  bool condition = condition1 && condition2 && condition3;
  std::cout << (condition ? "OK\n" : "NOK\n");
  delete deque;
}

int main()
{
  std::cout << "Class Deque:\n";
  Test_DeleteFirst();
  Test_DeleteLast();
  return 0;
}
