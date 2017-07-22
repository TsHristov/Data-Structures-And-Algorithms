#include <iostream>
#include "dynamic_array.h"

void Test_CreateDynamicArray()
{
  std::cout << "can create empty array...";
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

void Test_CountElements()
{
  std::cout << "can count the elements with particular value...";
  DynamicArray<int> array;
  array.Append(1);
  array.Append(1);
  array.Append(1);
  array.Append(2);
  bool condition = array.Count(1) == 3;
  std::cout << (condition ? "OK\n" : "NOK\n");
}

void Test_ReverseSequence()
{
  std::cout << "can reverse the sequence...";
  DynamicArray<int> array;
  for(int i = 0; i < 10; i++)
  {
    array.Append(i);
  }
  array.Reverse();
  bool condition = true;
  for(int i = 9, j = 0; i > 0 && j < 10; i--, j++)
  {
    if(array[j] != i) condition = false;
  }
  std::cout << (condition ? "OK\n" : "NOK\n");
}

void Test_Insert()
{
  std::cout << "can insert an element at given index...";
  DynamicArray<int> array;
  for(int i = 0; i < 5; i++)
  {
    array.Append(i);
  }
  array.Insert(1,666);
  bool condition = array.Index(666) == 1;
  std::cout << (condition ? "OK\n" : "NOK\n");
}

void Test_Empty()
{
  std::cout << "can check if container is empty...";
  DynamicArray<int> array;
  bool condition1 = array.IsEmpty();
  array.Append(0);
  bool condition2 = !array.IsEmpty();
  std::cout << (condition1 && condition2 ? "OK\n" : "NOK\n");
}

int main()
{
  std::cout << "Class DynamicArray: \n";
  Test_CreateDynamicArray();
  Test_AppendToArray();
  Test_GetIndexOfElement();
  Test_CountElements();
  Test_ReverseSequence();
  Test_Insert();
  Test_Empty();
  return 0;
}
