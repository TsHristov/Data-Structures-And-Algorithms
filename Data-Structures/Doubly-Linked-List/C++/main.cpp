#include "doubly_linked_list.h"

void Test_InsertFirst()
{
  DoublyLinkedList<int> list;
  list.InsertFirst(1);
  list.InsertFirst(2);
  bool condition1 = list.First() == 2;
  bool condition2 = list.Last()  == 1;
  bool condition  = condition1 && condition2;
  std::cout << (condition ? "OK\n" : "NOK\n");
}

int main()
{
  std::cout << "Class DoublyLinkedList:\n";
  Test_InsertFirst();
  return 0;
}
