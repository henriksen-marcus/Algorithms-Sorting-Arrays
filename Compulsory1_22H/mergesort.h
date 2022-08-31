#pragma once

#include <iostream>

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
	for (int i{}; i < size1; i++) { leftArr[i] = arr[start + i]; }
	for (int i{}; i < size2; i++) { rightArr[i] = arr[middle + 1 + i]; }

	int index0 = start, index1{}, index2{};

	// Run no more iterations than the smallest array size
	// index0 = index of original (to-be merged) array
	while (index1 < size1 && index2 < size2)
	{
		if (leftArr[index1] < rightArr[index2])		// Always push the smallest number in
		{											// the two arrays to the leftmost position
			arr[index0] = leftArr[index1];			// in the original array
			index1++;
		}
		else {
			arr[index0] = rightArr[index2];
			index2++;
		}
		index0++;
	}

	// Copy over leftovers
	if (index1 < size1)
	{
		for (index1; index1 < size1; index1++, index0++)
		{
			arr[index0] = leftArr[index1];
		}
	}

	if (index2 < size2)
	{
		for (index2; index2 < size2; index2++, index0++)
		{
			arr[index0] = rightArr[index2];
		}
	}

	delete[] leftArr;
	delete[] rightArr;
}


template<class T>
void mergesort(DynArr<T>& arr, int start, int end)
{
	if (start < end)
	{
		int middle = (start + end) / 2;

		mergesort(arr, start, middle); // Left
		mergesort(arr, middle + 1, end); // Right
		merge(arr, start, middle, end);
	}
}


template<class T>
void mergesort(DynArr<T>& arr)
{
	mergesort(arr, 0, arr.Size() - 1);
}