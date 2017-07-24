#include <iostream>
#include "linked_list.h"

void Test_PushFront()
{
  std::cout << "can insert at the beginning of the list...";
  LinkedList<char> list;
  list.PushFront('a');
  bool condition1 = !list.Empty();
  bool condition2 = list.First() == 'a';
  std::cout << ((condition1 && condition2) ? "OK\n" : "NOK\n");
}

void Test_PopFront()
{
  std::cout << "can remove from the beginning of the list...";
  LinkedList<char> list;
  list.PushFront('a');
  list.PushFront('b');
  bool condition1 = list.PopFront() == 'b';
  bool condition2 = list.PopFront() == 'a';
  bool condition3 = false;
  try
  {
    // Try to pop from empty list:
    list.PopFront();
  }catch(EmptyList& e)
  {
    condition3 = true;
  }
  bool condition = condition1 && condition2 && condition3;
  std::cout << ((condition) ? "OK\n" : "NOK\n");
}

void Test_PushBack()
{
  std::cout << "can insert at the end of the list...";
  LinkedList<char> list;
  list.PushBack('a');
  bool condition1 = !list.Empty();
  bool condition2 = list.Last() == 'a';
  std::cout << ((condition1 && condition2) ? "OK\n" : "NOK\n");
}

void Test_CopyConstructor()
{
  std::cout << "can create an instance from another one...";
  LinkedList<int> list;
  for(int i = 0; i < 10; i++)
  {
    list.PushBack(i);
  }
  LinkedList<int> other(list);
  bool condition = true;
  for(int i = 0; i < 10; i++)
  {
    if(other.PopFront() != i) condition = false;
  }
  std::cout << ( condition ? "OK\n" : "NOK\n");
}

void Test_OperatorEqual()
{
  std::cout << "can create an instance from another one using operator=...";
  LinkedList<int> list;
  for(int i = 0; i < 10; i++)
  {
    list.PushBack(i);
  }
  LinkedList<int> other;
  other = list;
  bool condition = true;
  for(int i = 0; i < 10; i++)
  {
    if(other.PopFront() != i) condition = false;
  }
  std::cout << ( condition ? "OK\n" : "NOK\n");
}

int main()
{
  std::cout << "Class LinkedList: \n";
  Test_PushFront();
  Test_PopFront();
  Test_PushBack();
  Test_CopyConstructor();
  Test_OperatorEqual();
  return 0;
}
