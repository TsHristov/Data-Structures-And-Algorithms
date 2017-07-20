#include "dynamic_array.h"

template<class T>
DynamicArray<T>::DynamicArray()
{
	size     = 0;
	capacity = 3;
	phead    = new T[capacity];
}

template<class T>
DynamicArray<T>::~DynamicArray()
{
	Free();
}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray& o)
{
	phead = new T[o.capacity];
	for (size_t i = 0; i <= o.size; ++i){
		phead[i] = o.phead[i];
	}
	size = o.size;
	capacity = o.capacity;
}

template<class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& o)
{
	if (this == &o)
  {
		return *this;
	}
	else
  {
		Free();
		phead = new T[o.capacity];
		for (size_t i = 0; i < o.capacity; ++i)
    {
			phead[i] = o.phead[i];
		}
		size     = o.size;
		capacity = o.capacity;
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
	return phead[index];
}

template<class T>
void DynamicArray<T>::Insert(T element)
{
	if (size == capacity)
	{
		this->Resize();
	}
	phead[size++] = element;
}

template<class T>
void DynamicArray<T>::Resize()
{
	T* pToResized = new T[capacity * 2];
	for (size_t i = 0; i < capacity; ++i){
		pToResized[i] = phead[i];
	}
	delete[] phead;
	capacity *= 2;
	phead = pToResized;
}

template<class T>
void DynamicArray<T>::RemoveElement()
{
	--size;
}

template<class T>
void DynamicArray<T>::Free()
{
	if (phead)
  {
		delete[] phead;
		phead = NULL;
	}
	size = 0;
	capacity = 0;
}

template<class T>
void DynamicArray<T>::Print() const
{
	for (int i = 0; i < capacity; ++i){
		std::cout << phead[i];
	}
	std::cout << '\n';
}

template<class T>
size_t DynamicArray<T>::GetSize() const
{
	return size;
}
