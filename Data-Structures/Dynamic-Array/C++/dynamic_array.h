#include<iostream>
#include "exceptions.h"
#include "iterator.h"

template<class T>
class DynamicArray
{
private:
  size_t size;
  size_t capacity;
  T * array;

public:
  DynamicArray();
  ~DynamicArray();
  DynamicArray(const DynamicArray&);
  DynamicArray& operator=(const DynamicArray&);

public:
  int Index(T value) const;
  int Count(T value) const;
  void Reverse();
  void Insert(size_t index, T value);
  void Print() const;
  void Append(T value);
  bool Empty() const { return size == 0; }
  DynamicArray& Expand(DynamicArray& other) { return operator+=(other); }
  T Pop();
  T Pop(size_t index);
  T& First() const { if(Empty()) throw EmptyArray(); else return array[0]; }
  T& Last()  const { if(Empty()) throw EmptyArray(); else return array[size-1]; }
  size_t GetSize() const { return size; }
  size_t GetCapacity() const { return capacity; }

public:
  T& operator[](size_t index);
  bool operator==(const DynamicArray&);
  bool operator!=(const DynamicArray&);
  DynamicArray& operator+=(DynamicArray&);
  const DynamicArray operator+(DynamicArray& other) const
  {
    return DynamicArray<T>(*this) += other;
  }

public:
  ForwardIterator<T> GetForwardIterator() const
  {
    T * temp = array;
    return ForwardIterator<T>(temp, size);
  }

  ReverseIterator<T> GetReverseIterator() const
  {
    T * temp = array;
    return ReverseIterator<T>(temp, size);
  }


public:
  void Resize(size_t);

private:
  void Free();
  void CopyFrom(const DynamicArray&);
};

template<class T>
DynamicArray<T>::DynamicArray()
{
  size     = 0;
  capacity = 4;
  array    = new T[capacity];
}

template<class T>
DynamicArray<T>::~DynamicArray()
{
  Free();
}

template<class T>
void DynamicArray<T>::CopyFrom(const DynamicArray& other)
{
  array = new T[other.capacity];
  for (size_t i = 0; i <= other.size; ++i)
  {
    array[i] = other.array[i];
  }
  size     = other.size;
  capacity = other.capacity;
}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray& other)
{
  CopyFrom(other);
}

template<class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other)
{
  if (this == &other) return *this;
  else
  {
    Free();
    CopyFrom(other);
    return *this;
  }
}

template<class T>
T& DynamicArray<T>::operator[](size_t index)
{
  if (index < 0 || index >= capacity) throw std::out_of_range("Index Out Of Range!");
  return array[index];
}

template<class T>
void DynamicArray<T>::Append(T value)
{
  if (size == capacity) Resize(capacity * 2);
  array[size++] = value;
}

template<class T>
void DynamicArray<T>::Resize(size_t new_capacity)
{
  T * resized = new T[new_capacity];
  for (size_t i = 0; i < size; ++i)
  {
    resized[i] = array[i];
  }
  delete[] array;
  capacity = new_capacity;
  array    = resized;
}

template<class T>
T DynamicArray<T>::Pop()
{
  if(Empty()) throw EmptyArray();
  else
  {
    T last = array[--size];
    if (size == (capacity/4)) Resize(capacity/2);
    return last;
  }
}

template<class T>
T DynamicArray<T>::Pop(size_t index)
{
  if(index >= size) throw std::out_of_range("Index Out Of range");
  else
  {
    T item = array[index];
    for(size_t i = index; i < size; i++)
    {
      array[index] = array[index+1];
    }
    --size;
    if(size == (capacity/4)) Resize(capacity/4);
    return item;
  }
}

template<class T>
void DynamicArray<T>::Free()
{
  if (array)
  {
    delete[] array;
    array = NULL;
  }
  size     = 0;
  capacity = 0;
}

template<class T>
void DynamicArray<T>::Print() const
{
  std::cout << "Capacity:" << capacity << "\n";
  std::cout << "Size:" << size << "\n";
  std::cout << "[";
  for(ForwardIterator<T> i = GetForwardIterator(); !i.End(); i.Next())
    std::cout << " " << i.Get();
  std::cout << " ]";
  std::cout << "\n";
}

template<class T>
int DynamicArray<T>::Count(T value) const
{
  int count = 0;
  for(size_t i = 0; i < size; i++)
  {
    if(array[i] == value) ++count;
  }
  return count;
}

template<class T>
int DynamicArray<T>::Index(T value) const
{
  size_t i;
  for(i = 0; i < size; i++)
  {
    if(array[i] == value) return i;
  }
  return -1;
}

template<class T>
void DynamicArray<T>::Reverse()
{
  size_t start = 0;
  size_t stop  = size - 1;
  while(start < stop)
  {
    T temp = array[start];
    array[start++] = array[stop];
    array[stop--]  = temp;
  }
}

template<class T>
void DynamicArray<T>::Insert(size_t index, T value)
{
  size_t i;
  for(i = GetSize(); i > index; i--)
  {
    array[i] = array[i-1];
  }
  ++size;
  if(size == capacity) Resize(capacity * 2);
  array[i] = value;
}

template<class T>
bool DynamicArray<T>::operator==(const DynamicArray& other)
{
  if(this == &other) return true;
  int this_lenght  = size;
  int other_lenght = other.GetSize();
  if(this_lenght != other_lenght) return false;
  for(size_t i = 0; i < size; i++)
  {
    if(array[i] != other.array[i]) return false;
  }
  return true;
}

template<class T>
bool DynamicArray<T>::operator!=(const DynamicArray& other)
{
  return !(*this == other);
}

template<class T>
DynamicArray<T>& DynamicArray<T>::operator+=(DynamicArray& other)
{
  size_t other_size = other.GetSize();
  for(size_t i = 0; i < other_size; i++)
  {
    Append(other[i]);
  }
  return *this;
}
