#include "declarations.h"

using namespace std;



int main()
{
    int* jsl = new int[3] { 1, 2, 3 };

    DynArr<int> myArr;

    myArr.Add(6);
    myArr.Add(4);
    myArr.Add(2);
    myArr.Add(9);
    myArr.Print();

    myArr = jsl;

    myArr.Print();
    //bubblesort(myArr);


    return 0;
}


