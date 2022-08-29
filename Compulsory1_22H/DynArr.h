#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/**
 * \brief A dynamic, expandable and retractable array, much like std::vector.
 * \tparam T The type you want the dynamic array to hold.
 * \remarks Why are we not using a .cpp file for the code? Template classes do not accept
 * file splitting. This way we avoid external errors. Else code will not compile.
 */
template <class T>
class DynArr
{
public:
	DynArr();
	~DynArr();

	enum SearchAlgorithm
	{
		Linear,
		Binary
	};

	string Alphabet = "abcdefghijklmnopqrstuvwxyz";

	/**
	 * \brief Sets all values from 'start' to array end to 0.
	 * \param start The index to initialize from, inclusive.
	 */
	void Init(int start);

	/**
	 * \brief Adds an item to the end of the array.
	 * \param item The item to add.
	 * \return The new array size.
	 */
	int Add(T item);

	/** Adds an empty slot at the end of the array. */
	void Expand();

	/**
	 * \brief Deletes the element at specified index. Shrinks array size after deletion.
	 * \param i The index to delete.
	 * \return The new array size.
	 */
	int Delete(int i);

	/**
	 * \brief Deletes a specified item in the array, if it exists.
	 * \param value The value/item to delete.
	 * \return The new array size.
	 */
	 int DeleteItem(T value);

	 /**
	  * \param value The item to find.
	  * \return The item index.
	  */
	int Find(T value, SearchAlgorithm alg);

	/**
	  * \brief Standard search that checks every array element from start to finish. 
	  * \param value The item to find.
	  * \return The item index.-1 if no value is found.
	  */
	int LinearSearch(T value);

	/**
	  * \brief Recursive search that splits the array in half every recursion while performing comparisons.
	  * \param value The item to find.
	  * \return The item index. -1 if no value is found.
	  * \remarks Only works with numbers.
	  */
	int BinarySearch(T value, int start, int end);

	/** \return Size of the array. */
	int Size() const;

	void Print();

	/**
	 * \brief Getter
	 * \param i The index.
	 * \return The element at the index.
	 */
	T At(int i);

	/**
	 * \brief Setter
	 * \param i The index.
	 */
	void Set(int i, T value);

	T* arr;

private:
	/** The amount of elements that are != NULL. */
	int ArrSize;

	/** The length of the array. */
	int MaxLength;

public:
	// Replace array
	/*void operator = (T& repl)
	{
		delete[] arr;
		arr = repl;
	}*/

	// Access and edit array elements
	T& operator [] (int i) { return arr[i]; }
};



// ----------------- FUNCTION DEFINITIONS ----------------- //



template<class T>
DynArr<T>::DynArr()
{
	ArrSize = 0;
	MaxLength = 0;
	arr = new T[MaxLength];
}

template<class T>
DynArr<T>::~DynArr()
{
	// Important! Clears memory.
	delete[] arr;
}

template<class T>
void DynArr<T>::Init(int start)
{
	for (int i = start; i < MaxLength; i++)
	{
		arr[i] = T();
	}
}


template<class T>
int DynArr<T>::Add(T item)
{
	Expand();
	arr[ArrSize - 1] = item; // Insert the new item
	return ArrSize;
}

template<class T>
void DynArr<T>::Expand()
{
	// Create temp array with new +1 length to hold old data
	T* TempArr = new T[++MaxLength];
	//std::copy(arr, arr + ArrSize, TempArr);

	// Copy over elements to temp array
	for (int i{}; i < MaxLength; i++)
	{
		TempArr[i] = arr[i];
	}

	delete[] arr;
	arr = TempArr;

	Init(ArrSize++);
}

template<class T>
int DynArr<T>::Delete(int i)
{
	T* TempArr = new T[MaxLength - 1];
	int j{}; // Temporary iterator
	
	for (int k{}; k < MaxLength; k++, j++)
	{
		if (k == i)
		{
			k++; // Skip over the index that we want to delete
		}
		TempArr[j] = arr[k];
	}
	MaxLength--;
	ArrSize--;

	delete[] arr;
	arr = TempArr;

	return ArrSize;
}

template<class T>
int DynArr<T>::DeleteItem(T value)
{
	int index = this->Find(value);
	if (index != -1) { return Delete(index); }
	return -1;
}

template<class T>
int DynArr<T>::Find(T value, SearchAlgorithm alg)
{
	return BinarySearch(value, 0, Size());
	/*switch (alg)
	{
	case LinearSearch:
		return LinearSearch(value);
	case BinarySearch:
		return BinarySearch(value, 0, Size());
	default:
		return -1;
	}*/
}

template<class T>
int DynArr<T>::LinearSearch(T value)
{
	for (int i{}; i < ArrSize; i++)
	{
		if (arr[i] == value)
		{
			return i;
		}
	}
	return -1;
}

template<class T>
int DynArr<T>::BinarySearch(T value, int start, int end)
{
	int middle = end - start;

	if (arr[middle] == value)
	{
		return middle;
	}
	else if (arr[middle] < value)
	{
		BinarySearch(value, middle + 1, Size());
	}
	else
	{
		BinarySearch(value, 0, middle - 1);
	}

	return -1;
}

template<class T>
int DynArr<T>::Size() const
{
	return ArrSize;
}

template<class T>
void DynArr<T>::Print()
{
	for (int i{}; i < ArrSize; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

	

































template<class T>
T DynArr<T>::At(int i)
{
	if (i >= ArrSize || i < 0)
	{
		std::cout << "Out of bounds!" << endl;
		throw;
	}
	else
	{
		return arr[i];
	}
}

template<class T>
void DynArr<T>::Set(int i, T value)
{
	if (i >= ArrSize || i < 0)
	{
		std::cout << "Out of bounds!" << endl;
		throw;
	}
	else
	{
		arr[i] = value;
	}
}
