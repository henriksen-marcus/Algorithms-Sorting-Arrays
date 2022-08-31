#pragma once

#include <iostream>
#include "sortingfunctions.h"

template<class T>
void selectionsort(DynArr<T>& arr)
{
	for (int i{}; i < arr.Size(); i++)
	{
		int smallestNumber = arr[i];
		int index{};
		for (int k{ i + 1 }; k < arr.Size(); k++)
		{
			if (arr[k] < smallestNumber)
			{
				smallestNumber = arr[k];
				index = k;
			}
		}
		if (index != 0) { swap(arr, i, index); }
	}
	printf("Array is sorted.\n");
}
