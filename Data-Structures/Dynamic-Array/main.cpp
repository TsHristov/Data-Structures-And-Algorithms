#include <iostream>
#include "dynamic_array.h"
using namespace std;

int main()
{
  DynamicArray<int> array1;
  for(size_t i = 0; i < 10; i++)
  {
    array1.Append(i);
  }
  DynamicArray<int> array2;
  for(size_t i = 10; i < 20; i++)
  {
    array2.Append(i);
  }
  DynamicArray<int> result;
  result = array1 + array2;
  array1.Print();
  array2.Print();
  result.Print();
  return 0;
}
