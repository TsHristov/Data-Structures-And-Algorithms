#include<iostream>
#pragma once
//TO-DO:
// *implement forward iterator
// *implement reverse iterator

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
		void Append(T value);
		T Pop(); // Remove and retrieve last element
		size_t GetSize() const;
		T& operator[](int);
		//TO-DO:
		int Index(T value) const;
		int Count(T value) const;
		// void Remove(T value);
		// void Reverse();
		// Insert value at given index
		// void Insert(int index=size-1, T value);
		void Print() const;

	private:
		void Resize(int);
		void Free();
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
DynamicArray<T>::DynamicArray(const DynamicArray& other)
{
	array = new T[other.capacity];
	for (size_t i = 0; i <= other.size; ++i){
		array[i] = other.array[i];
	}
	size     = other.size;
	capacity = other.capacity;
}

template<class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other)
{
	if (this == &other)
  {
		return *this;
	}
	else
  {
		Free();
		array = new T[other.capacity];
		for (size_t i = 0; i < other.capacity; ++i)
    {
			array[i] = other.array[i];
		}
		size     = other.size;
		capacity = other.capacity;
	}
	return *this;
}

template<class T>
T& DynamicArray<T>::operator[](int index)
{
	if (index < 0 || index > capacity - 1)
  {
		std::cout << "Index out of bounds!" << '\n';
		// TO-DO: Throw exception!
	}
	return array[index];
}

template<class T>
void DynamicArray<T>::Append(T value)
{
	if (size == capacity)
	{
		Resize(capacity * 2);
	}
	array[size++] = value;
}

template<class T>
void DynamicArray<T>::Resize(int new_capacity)
{
	std::cout  << "Resize() with " << new_capacity << "\n";
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
	T last = array[size--];
	if (size == (capacity/4))
	{
		Resize(capacity/2);
	}
	return last;
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
	for (size_t i = 0; i < size; ++i)
	{
		std::cout << " " << array[i];
	}
	std::cout << " ]";
	std::cout << "\n";
}

// O(n), where n is the size of the array
template<class T>
int DynamicArray<T>::Count(T value) const
{
	int counter = 0;
	for(size_t i = 0; i < size; i++)
	{
		if(array[i] == value)
		{
			++counter;
		}
	}
	return counter;
}

// Returns the first occurence of value
template<class T>
int DynamicArray<T>::Index(T value) const
{
	size_t i;
	for(i = 0; i < size; i++)
	{
		if(array[i] == value) break;
	}
	return i;
}


template<class T>
size_t DynamicArray<T>::GetSize() const
{
	return size;
}
