#pragma once

#include <iostream>
#include "sortingfunctions.h"
//#include <Windows.h>

using namespace std;


template <typename T>
void insertionsort(DynArr<T>& arr)
{
	for (int i{}; i < arr.Size() - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			swap(arr, i, i + 1);

			// Continue pushing the swapped number back until it's in the right position
			for (int k = i; k > 0; k--)
			{
				if (arr[k] > arr[k - 1])
				{
					break;
				}
				else
				{
					swap(arr, k, k - 1);
				}
			}
		}
	}
	cout << "Insertion Sort: Array is sorted." << endl;
}