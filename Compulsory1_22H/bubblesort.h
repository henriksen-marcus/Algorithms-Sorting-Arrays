#pragma once

#include <iostream>
#include "sortingfunctions.h"

template <typename T>
void bubblesort(DynArr<T>& arr);

template <typename T>
bool validate(DynArr<T>& arr);



// ----------------- FUNCTION DEFINITIONS ----------------- //



/** Check if the array is sorted. */
template <typename T>
bool validate(DynArr<T>& arr)
{
    for (int i{}; i < arr.Size() - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            return false;
        }
    }
    std::cout << "Bubble Sort: Array is sorted." << std::endl;
    return true;
}

template <typename T>
void bubblesort(DynArr<T>& arr)
{
    while (!validate(arr))
    {
        for (int i{}; i < arr.Size() - 1; i++)
        {
            if (arr[i] > arr[i + 1]) // Compare size of element i and the next element
            {
                swap(arr, i, i + 1);
                //break;
            }
        }
    }
}
