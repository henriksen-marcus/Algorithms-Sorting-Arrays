#pragma once

/**
	 * \brief Swap two array elements.
	 * \param arr The array in which to perform the swap, will edit array passed in, not a copy.
	 * \param a First element.
	 * \param b Second element.
	 */
template <typename T>
void swap(DynArr<T>& arr, int a, int b)
{
    int temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}