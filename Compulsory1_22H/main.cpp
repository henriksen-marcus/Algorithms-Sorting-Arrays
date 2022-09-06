#include "declarations.h"

using namespace std;



int main()
{
    DynArr<int> myArr;
    myArr.Push(76); 
    myArr.Push(8); 
    myArr.Push(0); 
    myArr.Push(21); 
    myArr.Push(15); 
    myArr.Push(91); 
    myArr.Push(6); 
    myArr.Push(2);
    myArr.Push(9);

    myArr.Print();
    quicksort(myArr);
    myArr.Print();

    invert(myArr);
    myArr.Print();

    printf("Index: %d", myArr.Find(21));

    return 0;
}