#pragma once

#include <iostream>
#include "DynArr.h"

using namespace std;

template <typename T>
void bubblesort(DynArr<T> arr);

template <typename T>
bool validate(DynArr<T> arr);

template <typename T>
void swap(DynArr<T> arr, int a, int b);



// ----------------- FUNCTION DEFINITIONS ----------------- //



/** Check if the array is sorted. */
template <typename T>
bool validate(DynArr<T> arr)
{
    for (int i{}; i < arr.size() - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            cout << "Validate: Array is not sorted" << endl;
            return false;
        }
    }
    cout << "Validate: Array is sorted" << endl;
    for (int k{}; k < arr.size(); k++)
    {
        cout << arr[k] << " ";
    }
    cout << endl;
    return true;
}

/** Swap two array elements' index. */
template <typename T>
void swap(DynArr<T> arr, int a, int b)
{
    int temp = arr->at(a);
    arr->at(a) = arr->at(b);
    arr->at(b) = temp;

    cout << "swapped " << arr->at(b) << " with " << arr->at(a) << endl;
}

template <typename T>
void bubblesort(DynArr<T> arr)
{
    while (!validate(arr))
    {
        for (int i{}; i < arr.size() - 1; i++)
        {
            if (arr[i] > arr[i + 1]) // Compare size of element i and the next element
            {
                swap(&arr, i, i + 1);

                for (int k{}; k < arr.size(); k++)
                {
                    cout << arr[k] << " ";
                }
                cout << endl;
                break;
            }
        }
    }
}
