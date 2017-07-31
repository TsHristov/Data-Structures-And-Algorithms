#include "queue.h"

void Test_Enqueue()
{
  std::cout << "can enqueue an element... ";
  Queue<int> queue;
  queue.Enqueue(1);
  bool condition1 = !queue.Empty();
  bool condition2 = queue.Last() == 1;
  bool condition  = condition1 && condition2;
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
  size_t size = queue.GetSize();
  bool condition2 = queue.Dequeue() == 1;
  bool condition3 = queue.GetSize() == size - 1;
  bool condition  = condition1 && condition2 && condition3;
  std::cout << (condition ? "OK\n" : "NOK\n");
}

int main()
{
  std::cout << "Class Queue:\n";
  Test_Enqueue();
  Test_Dequeue();
  return 0;
}
