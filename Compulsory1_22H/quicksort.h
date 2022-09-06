#pragma once

#include <iostream>
#include "DynArr.h"
#include "sortingfunctions.h"

using namespace std;

// References:
// https://www.youtube.com/watch?v=MZaf_9IZCrc
// https://www.geeksforgeeks.org/quick-sort/


/* Sorts a specified portion of a given array, putting
   all lesser numbers on the left, and larger on the right. */
int partition(DynArr<int>& arr, int start, int end)
{
	// We are only interested in the pivots value, because
	// that is our base of comparison. Pivot is always at end.
	int pivot = arr[end];

	// This number will iterate when finding an element
	// that is less than the pivot. Index placeholder.
	int leftwall = start - 1;

	// Pivot is last element, only go to (end - 1)
	for (int i = start; i <= end - 1; i++)
	{
		if (arr[i] < pivot)
		{
			leftwall++;
			swap(arr, leftwall, i);
		}
	}
	
	// Move pivot into correct position (where leftwall is)
	swap(arr, ++leftwall, end);
	return leftwall;
}

void qs(DynArr<int>& arr, int start, int end)
{
	if (start >= end) return;
		
	// This index will split the array, much like merge sort.
	// Then we will perform quicksort on the two halves.
	int middle = partition(arr, start, end);

	// Left half
	qs(arr, start, middle - 1);

	// Right half
	qs(arr, middle + 1, end);
}

void quicksort(DynArr<int>& arr)
{
	qs(arr, 0, arr.Size() - 1);
	cout << "Array is sorted.\n";
}