#pragma once

#include <iostream>
#include <vector>

using namespace std;

vector<int> myarr{ 5,4,3,2,1 };


/** Swap two array elements' index. */
inline void swap(vector<int>* arr, int a, int b)
{
	int temp = arr->at(a);
	arr->at(a) = arr->at(b);
	arr->at(b) = temp;

	cout << "swapped " << arr->at(b) << " with " << arr->at(a) << endl;
}

inline void insertionsort(vector<int>& arr)
{

	for (int i = 0; i < arr.size()-1; i++)
	{
		if (arr[i] > arr[i+1])
		{
			swap(&arr, i, i+1);

			for (int k = i; k > 0; k--)
			{
				if (arr[k] > arr[k - 1])
				{
					break;
				}
				else
				{
					swap(&arr, k, k - 1);
				}
			}
		}
	}

	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << arr[i] << " ";
	}
	cout << endl;
}