#include <iostream>
#include "dynamic_array.h"
using namespace std;

int main()
{
  DynamicArray<int> array;
  for(size_t i = 0; i <= 10; i++)
  {
    array.Append(i);
  }
  array.Print();
  array.Append(11);
  array.Append(12);
  array.Append(12);
  array.Append(12);
  array.Insert(0, 666);
  array.Print();
  return 0;
}
