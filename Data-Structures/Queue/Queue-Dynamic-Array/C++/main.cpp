#include "queue.h"

void Test_Enqueue()
{
  std::cout << "can enqueue an element... ";
  Queue<int> queue;
  queue.Enqueue(1);
  bool condition1  = !queue.Empty();
  bool condition2  = queue.First() == 1;
  bool condition   = condition1 && condition2;
  std::cout << (condition ? "OK\n" : "NOK\n");
}

void Test_Dequeue()
{
  std::cout << "can dequeue an element...";
  Queue<int> queue;
  bool condition1 = false;
  // Try to dequeue from an empty queue
  try
  {
    queue.Dequeue();
  }catch(EmptyQueue& e)
  {
    condition1 = true;
  }
  queue.Enqueue(1);
  queue.Enqueue(2);
  queue.Enqueue(3);
  queue.Enqueue(4);
  bool condition2 = true;
  for(size_t i = 1; i < 5; i++)
  {
    condition2 = queue.Dequeue() == i;
  }
  bool condition  = condition1 && condition2;
  std::cout << (condition ? "OK\n" : "NOK\n");
}

void Test_GetFirst()
{
  std::cout << "can get head of the queue...";
  Queue<int> queue;
  bool condtion1 = false;
  try
  {
    queue.First();
  }catch(EmptyQueue& e)
  {
    condtion1 = true;
  }
  queue.Enqueue(1);
  queue.Enqueue(2);
  size_t size = queue.GetSize();
  bool condition2 = queue.First() == 1;
  bool condition3 = queue.GetSize() == size;
  bool condition  = condtion1 && condition2 && condition3;
  std::cout << (condition ? "OK\n" : "NOK\n");
}

void Test_CopyConstructor()
{
  std::cout << "can create a queue from another one...";
  Queue<int> first;
  first.Enqueue(1);
  first.Enqueue(2);
  first.Enqueue(3);
  Queue<int> second(first);
  bool condition = true;
  for(size_t i = 1; i < 4; i++)
  {
    condition = second.Dequeue() == i;
  }
  std::cout << (condition ? "OK\n" : "NOK\n");
}

void Test_OperatorEqual()
{
  std::cout << "can create a queue from another one using operator=...";
  Queue<int> first;
  first.Enqueue(1);
  first.Enqueue(2);
  Queue<int> second;
  second.Enqueue(3);
  second = first;
  bool condition1 = first.GetSize() ==  second.GetSize();
  bool condition2 = second.Dequeue()  == 1;
  bool condition3 = second.Dequeue()  == 2;
  bool condition = condition1 && condition2 && condition3;
  std::cout << (condition ? "OK\n" : "NOK\n");
}

void Test_Compare()
{
  std::cout << "can compare two queues using == and !=...";
  Queue<int> first;
  Queue<int> second;
  bool condition1 = first == second;
  first.Enqueue(1);
  bool condition2 = first != second;
  second.Enqueue(1);
  bool condition3 = first == second;
  bool condition = condition1 && condition2 && condition3;
  std::cout << (condition ? "OK\n" : "NOK\n");
}

int main()
{
  std::cout << "Class Queue:\n";
  Test_Enqueue();
  Test_Dequeue();
  Test_GetFirst();
  Test_CopyConstructor();
  Test_OperatorEqual();
  Test_Compare();
  return 0;
}
