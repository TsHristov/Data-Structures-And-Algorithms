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

int main()
{
  std::cout << "Class DoublyLinkedList:\n";
  Test_InsertFirst();
  Test_InsertLast();
  return 0;
}
