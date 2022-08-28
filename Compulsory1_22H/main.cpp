#include "declarations.h"

using namespace std;



int main()
{

    DynArr<int> myArr;

    myArr.Add(6);
    myArr.Add(4);
    myArr.Add(9);
    myArr.Add(2);
    myArr.Add(1);
    myArr.Print();

    //bubblesort(myArr);
    //insertionsort(myArr);
    cout << myArr.Find(4, DynArr<int>::Binary);

   // myArr.Print();

    //int a = 14;
    //std::cout << (a >> 1);


    return 0;
}


