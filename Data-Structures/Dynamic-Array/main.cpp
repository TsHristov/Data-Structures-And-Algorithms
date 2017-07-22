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

void Test_Expand()
{
  std::cout << "can expand with new object...";
  DynamicArray<int> array1;
  array1.Append(1);
  array1.Append(2);
  DynamicArray<int> array2;
  array2.Append(1);
  array2.Append(2);
  DynamicArray<int> array3;
  array3.Append(3);
  array3.Append(4);
  array1.Expand(array3);
  array2 += array3;
  bool condition = true;
  for(int i = 0 ; i < 4; i++)
  {
    if(array1[i] != i + 1 || array2[i] != i + 1) condition = false;
  }

  std::cout << (condition ? "OK\n" : "NOK\n");
}

void Test_Pop()
{
  std::cout << "can pop an element from the end...";
  DynamicArray<int> array;
  array.Append(1);
  array.Append(2);
  bool condition1 = array.Pop(1)  == 2;
  bool condition2 = array.Pop() == 1;
  bool condition3 = false;
  try
  {
    // Try to Pop() from empty array:
    array.Pop();
  }catch(EmptyArray& e)
  {
    condition3 = true;
  }
  bool condition = condition1 && condition2 && condition3;
  std::cout << (condition ? "OK\n" : "NOK\n");
}

void Test_GetFirstAndLast()
{
  std::cout << "can get the first element...";
  DynamicArray<int> array;
  array.Append(1);
  array.Append(2);
  bool condition = array.First() == 1;
  std::cout << (condition ? "OK\n" : "NOK\n");
  std::cout << "can get the last element...";
  condition = array.Last() == 2;
  std::cout << (condition ? "OK\n" : "NOK\n");
}

void Test_OperatorSquareBrackets()
{
  std::cout << "can get the element using []...";
  DynamicArray<int> array;
  array.Append(1);
  array.Append(2);
  bool condition1 = array[0] == 1;
  array[0] = 5;
  bool condition2 = array[0] == 5;
  std::cout << (condition1 && condition2 ? "OK\n" : "NOK\n");
}

void Test_Compare()
{
  std::cout << "can compare two instances with ==...";
  DynamicArray<int> array1;
  array1.Append(1);
  array1.Append(2);
  DynamicArray<int> array2;
  array2.Append(1);
  array2.Append(2);
  bool condition = array1 == array2;
  std::cout << (condition ? "OK\n" : "NOK\n");
  std::cout << "can compare two instances with !=...";
  array1[0] = 5;
  condition = array1 != array2;
  std::cout << (condition ? "OK\n" : "NOK\n");
}

void Test_Resize()
{
  std::cout << "can double the capacity if size == capacity...";
  DynamicArray<int> array;
  bool condition1 = array.GetCapacity() == 4;
  for(size_t i = 0; i < 5; i++)
  {
    array.Append(i);
  }
  bool condition2 = array.GetCapacity() == 8;
  std::cout << (condition1 && condition2 ? "OK\n" : "NOK\n");
  std::cout << "can half the capacity if array is 25% full...";
  for(size_t i = 0; i < 3; i++)
  {
    array.Pop();
  }
  bool condition3 = array.GetCapacity() == 4;
  std::cout << (condition3 ? "OK\n" : "NOK\n");
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
  Test_Expand();
  Test_Pop();
  Test_GetFirstAndLast();
  Test_OperatorSquareBrackets();
  Test_Compare();
  Test_Resize();
  return 0;
}
