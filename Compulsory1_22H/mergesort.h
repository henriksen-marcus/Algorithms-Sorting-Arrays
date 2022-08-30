#pragma once

#include <iostream>
#include <cstring>
#include <algorithm>

template<class T>
void mergesort(DynArr<T>& arr, int start, int end);

template<class T>
void merge(DynArr<T>& arr, int start, int middle, int end);

template<class T>
void mergesort(DynArr<T>& arr, int start, int end)
{
	if (start < end) 
	{
		int middle = (start + end) >> 1;
		mergesort(arr, start, middle); // Left
		mergesort(arr, middle + 1, end); // Right
		merge(arr, start, middle, end);
	}
}

template<class T>
void merge(DynArr<T>& arr, int start, int middle, int end)
{
	// Size of left temp array
	int size1 = middle - start + 1;
	// Size of right temp array
	int size2 = end - middle;

	// Init temp arrays 
	T* leftArr = new T[size1];
	T* rightArr = new T[size2];

	// Copy over data to temp arrays, to use in comparisons
	memmove(leftArr, arr, arr.arr + size1);
	memmove(rightArr, arr + middle + 1, middle + 1 + end);

	int index0{},index1{}, index2{};

	// Run no more iterations than the smallest array size
	// index0 = index of original (to-be merged) array
	for (index0 = start; index0 < min(size1, size2); index0++)
	{
		if (leftArr[index1] <= rightArr[index2])	// Always push the smallest number in
		{											// the two arrays to the leftmost position
			memmove(arr[left], leftArr[index1], T); // in the original array.
			index1++;
		}
		else {
			memove(arr[left], rightArr[index2], T);
			index2++;
		}
	}
	index0++;

	if (index1 < size1) memmove(arr[index0], leftArr[index1], leftArr[index1] + size1);
	if (index2 < size2) memmove(arr[index0], rightArr[index1], rightArr[index1] + size2);

	delete[] leftArr;
	delete[] rightArr;
}