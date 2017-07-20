#include<iostream>
#pragma once

template<class T>
class DynamicArray
{
	private:
		size_t size;
		size_t capacity;
		T* phead;

	public:
		DynamicArray();
		~DynamicArray();
		DynamicArray(const DynamicArray&);
		DynamicArray& operator=(const DynamicArray&);

	private:
		void Resize();
		void Free();

	public:
		void Insert(T);
		void RemoveElement();
		T& operator[](int);
		size_t GetSize() const;
		void Print() const;
};
