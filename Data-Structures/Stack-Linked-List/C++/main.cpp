#include "stack.h"

void Test_Push()
{
  std::cout << "can push onto the stack...";
  Stack<int> stack;
  stack.Push(1);
  stack.Push(2);
  bool condition = !stack.Empty();
  std::cout << (condition ? "OK\n" : "NOK\n");
}

void Test_Pop()
{
  std::cout << "can pop from the stack...";
  Stack<int> stack;
  for(int i = 0; i < 10; i++) stack.Push(i);
  bool condition1 = true;
  for(int i = 9; i >= 0; i--) condition1 = stack.Pop() == i;
  bool condition2 = false;
  try
  {
    // Try to pop from an empty stack:
    stack.Pop();
  }catch(EmptyList& e)
  {
    condition2 = true;
  }
  std::cout << ((condition1 && condition2) ? "OK\n" : "NOK\n");
}

void Test_GetSize()
{
  std::cout << "can get the size of the stack...";
  Stack<int> stack;
  for(int i = 0; i < 10; i++) stack.Push(i);
  bool condition = stack.GetSize() == 10;
  std::cout << (condition ? "OK\n" : "NOK\n");
}

void Test_GetTop()
{
  std::cout << "can get the top element...";
  Stack<int> stack;
  stack.Push(1);
  stack.Push(2);
  bool condition1 = stack.Top() == 2;
  bool condition2  = stack.GetSize() == 2;
  stack.Pop();
  stack.Pop();
  bool condition3 = false;
  try
  {
    stack.Top();
  }catch(EmptyList& e)
  {
    condition3 = true;
  }
  bool condition = condition1 && condition2 && condition3;
  std::cout << (condition ? "OK\n" : "NOK\n");
}

void Test_Create()
{
  std::cout << "can construct a stack from another one...";
  Stack<int> stack1;
  stack1.Push(1);
  stack1.Push(2);
  Stack<int> stack2(stack1);
  bool condition1 = stack2 == stack1;
  stack2.Push(3);
  stack1 = stack2;
  bool condition2 = stack1.Top() == 3;
  bool condition  = condition1 && condition2;
  std::cout << (condition ? "OK\n" : "NOK\n");
}

void Test_Compare()
{
  std::cout << "can compare two stacks...";
  Stack<int> stack1;
  stack1.Push(1);
  stack1.Push(2);
  Stack<int> stack2;
  stack2.Push(1);
  stack2.Push(2);
  bool condition1 = stack1 == stack2;
  stack2.Push(3);
  bool condition2 = stack1 != stack2;
  bool condition  = condition1 && condition2;
  std::cout << (condition ? "OK\n" : "NOK\n");
}

int main()
{
  std::cout << "Class Stack: \n";
  Test_Create();
  Test_Compare();
  Test_Push();
  Test_Pop();
  Test_GetSize();
  Test_GetTop();
  return 0;
}
