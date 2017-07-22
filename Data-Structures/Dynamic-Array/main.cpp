#include <iostream>
#include "dynamic_array.h"

void Test_CreateDynamicArray()
{
  std::cout << "Can create empty array...";
  DynamicArray<int> array;
  std::cout << "OK\n";
}

void Test_AppendToArray()
{
  std::cout << "can append value to end of array...";
  DynamicArray<int> array;
  array.Append(10);
  std::cout << (array.Last() == 10 ? "OK\n" : "NOK\n");
}

void Test_GetIndexOfElement()
{
  std::cout << "can retrieve the index of an element...";
  DynamicArray<int> array;
  array.Append(10);
  bool condition1 = array.Index(10) == 0;
  bool condition2 = array.Index(-666) == -1;
  std::cout << (condition1 && condition2 ? "OK\n" : "NOK\n");
}

int main()
{
  std::cout << "Class DynamicArray: \n";
  Test_CreateDynamicArray();
  Test_AppendToArray();
  Test_GetIndexOfElement();
  return 0;
}
