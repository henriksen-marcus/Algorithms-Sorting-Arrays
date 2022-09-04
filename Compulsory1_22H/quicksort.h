#pragma once

#include "DynArr.h"
#include <iostream>
#include "sortingfunctions.h"

// References:
// https://www.youtube.com/watch?v=MZaf_9IZCrc

int partition(DynArr<int>& arr, int start, int end)
{
	int pivot = arr[end], leftwall = start - 1;

	for (int i = start; i < end - 1; i++)
	{
		if (arr[i] < pivot)
		{
			leftwall++;
			swap(arr, leftwall, i);
		}
	}
	
	// Move pivot into correct position
	swap(arr, ++leftwall, end);
	return leftwall;
}

void qs(DynArr<int>& arr, int start, int end)
{
	if (start >= end) return;

	int pivot = partition(arr, start, end);

	qs(arr, start, pivot - 1);
	qs(arr, pivot + 1, end);

	// Move pivot to the back
	//if (pivot != (arr.Size() - 1)) swap(arr, pivot, arr.Size() - 1);
	
	
}

void quicksort(DynArr<int>& arr)
{
	int end = arr[arr.Size() - 1];
	qs(arr, 0, end);
}