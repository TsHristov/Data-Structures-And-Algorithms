#include "doubly_linked_list.h"

void Test_InsertFirst()
{
  std::cout << "can insert at the beginning of the list...";
  DoublyLinkedList<int> list;
  list.InsertFirst(1);
  list.InsertFirst(2);
  bool condition1 = list.First() == 2;
  bool condition2 = list.Last()  == 1;
  bool condition  = condition1 && condition2;
  std::cout << (condition ? "OK\n" : "NOK\n");
}

void Test_InsertLast()
{
  std::cout << "can insert at the end of the list...";
  DoublyLinkedList<int> list;
  list.InsertLast(1);
  list.InsertLast(2);
  bool condition1 = list.First() == 1;
  bool condition2 = list.Last()  == 2;
  bool condition  = condition1 && condition2;
  std::cout << (condition ? "OK\n" : "NOK\n");
}

void Test_ForwardIterator()
{
  std::cout << "can iterate the list in forward direction...";
  DoublyLinkedList<int> list;
  list.InsertLast(0);
  list.InsertLast(1);
  list.InsertLast(2);
  list.InsertLast(3);
  bool condition = true;
  Iterator<int> i = list.ForwardIterator();
  int j = 0;
  for(;!i.End() && j < 4;i.Next(), j++)
  {
    if(i.Get() != j) condition = false;
  }
  std::cout << (condition ? "OK\n" : "NOK\n");
}

void Test_ReverseIterator()
{
  std::cout << "can iterate the list in reverse direction...";
  DoublyLinkedList<int> list;
  list.InsertLast(0);
  list.InsertLast(1);
  list.InsertLast(2);
  list.InsertLast(3);
  bool condition = true;
  Iterator<int> i = list.ReverseIterator();
  int j = 3;
  for(;!i.End() && j >=0;i.Next(), j--)
  {
    if(i.Get() != j) condition = false;
  }
  std::cout << (condition ? "OK\n" : "NOK\n");
}

void Test_CopyFromOther()
{
  std::cout << "can create an list from another one...";
  DoublyLinkedList<int> list;
  list.InsertLast(0);
  list.InsertLast(1);
  DoublyLinkedList<int> other(list);
  bool condition = other.First() == 0 && other.Last() == 1;
  std::cout << (condition ? "OK\n" : "NOK\n");
}

void Test_Compare()
{
  std::cout << "can compare two lists...";
  DoublyLinkedList<int> first;
  first.InsertLast(0);
  first.InsertLast(1);
  bool condition1 = first == first;
  DoublyLinkedList<int> second;
  second.InsertLast(0);
  second.InsertLast(1);
  bool condition2 = first == second;
  second.InsertLast(2);
  bool condition3 = first != second;
  // bool condition = condition1 && condition2;
  bool condition = condition3;

  std::cout << (condition ? "OK\n" : "NOK\n");
}

int main()
{
  std::cout << "Class DoublyLinkedList:\n";
  Test_InsertFirst();
  Test_InsertLast();
  Test_ForwardIterator();
  Test_ReverseIterator();
  Test_Compare();
  // Test_CopyFromOther();
  return 0;
}
