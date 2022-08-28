#pragma once

#include <iostream>

template<class T>
void mergesort(DynArr<T>& arr);

template<class T>
void merge(DynArr<T>& arr1, DynArr<T>& arr2);

template<class T>
void mergesort(DynArr<T>& arr)
{
	if (arr.Size() <= 2) {}
	int middle = arr.Size() >> 1;
}

template<class T>
void merge(DynArr<T>& arr1, DynArr<T>& arr2)
{

}