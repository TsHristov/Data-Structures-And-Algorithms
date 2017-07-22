#include <iostream>
#include "dynamic_array.h"
using namespace std;

int main()
{
  DynamicArray<int> array;
  for(size_t i = 0; i <= 20; i++)
  {
    array.Append(i);
  }
  size_t size = array.GetSize();
  while(size > 8)
  {
    cout << array.Pop() << "\n";
    --size;
  }
  array.Print();
  for(size_t i = 0; i < 9; i++)
  {
    array.Append(i);
  }
  array.Print();
  return 0;
}
