#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <exception>

template <typename T>
class Array
{
	private:
		T *arrayBlock;
		unsigned int memSize;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &sourceArray);
		Array &operator=(const Array& sourceArray);
		T &operator[](unsigned int index)const;
		unsigned int size()const;
		~Array();

};

template <typename T>
Array<T>::Array()
{
	arrayBlock = NULL;
	memSize = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	arrayBlock  = new T[n];
	memSize = n;
}

template <typename T>
unsigned int Array<T>::size()const
{
	return memSize;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array& sourceArray)
{
	delete[] arrayBlock;
	arrayBlock = new T[sourceArray.size()];
	memSize = sourceArray.size();
	for (int index = 0; (unsigned)index < memSize; index++)
		arrayBlock[index] = sourceArray[index];
	return *this;
}

template <typename T>
Array<T>::Array(const Array &sourceArray)
{
	arrayBlock = NULL;
	*this = sourceArray;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)const
{
	if (index >= memSize)
		throw std::exception();
	return arrayBlock[index];
}

template <typename T>
Array<T>::~Array(){
	delete[] arrayBlock;
}

#endif