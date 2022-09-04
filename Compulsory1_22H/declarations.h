#pragma once

#include <iostream>
#include <string>
#include "DynArr.h"
#include "bubblesort.h"
#include "insertionsort.h"
#include "mergesort.h"
#include "selectionsort.h"
#include "quicksort.h"


template<typename T>
bool operator < (DynArr<T>& input1, DynArr<T>& input2)
{
    int sum1{}, sum2{};
    for (int i{}; i < input1.Size(); i++) { input1[i] += sum1; }
    for (int i{}; i < input2.Size(); i++) { input2[i] += sum2; }
    return sum1 < sum2 ? true : false;
}