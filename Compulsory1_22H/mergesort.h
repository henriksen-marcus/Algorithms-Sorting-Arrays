#pragma once

#include <iostream>
//#include <cstring>
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
		int middle = (start + end) / 2;

		cout << "Split the array! middle = " << middle << endl;
		for (int i{ start }; i <= middle; i++)
		{
			if (i == middle)
			{
				cout << ">" << arr[i] << " ";
			}
			else
			{
				cout << arr[i] << " ";
			}
		}
		cout << " || ";
		for (int i{ middle + 1 }; i <= end; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl << endl;

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

	cout << "Merge! LSize: " << size1 << " RSize: " << size2 << endl;

	// Init temp arrays 
	T* leftArr = new T[size1];
	T* rightArr = new T[size2];

	// Copy over data to temp arrays, to use in comparisons
	for (int i{}; i < size1; i++) { leftArr[i] = arr[start + i]; }
	for (int i{}; i < size2; i++) { rightArr[i] = arr[middle + 1 + i]; }

	printf("merging [");
	for (int i{}; i < size1; i++) { printf("%d ", leftArr[i]); }
	printf("] with [");
	for (int i{}; i < size2; i++) { printf(" %d", rightArr[i]); }
	printf("]\n");
	//printf("running %d loops\n", min(size1, size2));

	int index0 = start, index1{}, index2{};
	int zeroindex = 0;

	printf("index0: %d, size1: %d, size2: %d\n", index0 - start, size1, size2);

	// Run no more iterations than the smallest array size
	// index0 = index of original (to-be merged) array
	while (index1 < size1 && index2 < size2)
	{
		printf("[comparing %d to %d]\n", leftArr[index1], rightArr[index2]);
		if (leftArr[index1] < rightArr[index2])	// Always push the smallest number in
		{
			printf("inserted %d\n", leftArr[index1]);								// the two arrays to the leftmost position
			arr[index0] = leftArr[index1];			// in the original array
			index1++;
		}
		else {
			printf("inserted %d\n", rightArr[index2]);
			arr[index0] = rightArr[index2];
			index2++;
		}
		index0++;
		zeroindex++;
		printf("indexes: ind1:%d, ind2:%d\n", index1, index2);
	}
	/*for (index0 = start; index0 < min(size1, size2); index0++)
	{

	}*/

	// Copy over leftovers
	if (index1 < size1)
	{
		printf("Leftover elements in leftArr: %d\n", (size1)-index1);
		for (index1; index1 < size1; index1++, index0++)
		{
			arr[index0] = leftArr[index1];
		}
	}

	if (index2 < size2)
	{
		printf("Leftover elements in rightArr: %d\n", (size2)-index2);
		for (index2; index2 < size2; index2++, index0++)
		{
			arr[index0] = rightArr[index2];
		}
	}

	delete[] leftArr;
	delete[] rightArr;

	cout << "merge result: [";
	for (int i{ start }; i <= end; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "]" << endl;
}