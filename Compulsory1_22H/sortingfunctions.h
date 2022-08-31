#pragma once

/**
	 * \brief Swap two array elements.
	 * \param arr The array in which to perform the swap, will edit array passed in, not a copy.
	 * \param a First element.
	 * \param b Second element.
	 */
template <class T>
void swap(DynArr<T>& arr, int a, int b)
{
    T temp = arr[a];
    arr[a] = arr[b];
    arr[b] = temp;
}

template<class T>
void invert(DynArr<T>& arr)
{
	int k = arr.Size() - 1;
	for (int i{}; i < arr.Size() >> 1; i++, k--)
	{
		swap(arr, i, k);
	}
}