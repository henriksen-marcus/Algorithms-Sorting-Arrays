#include "declarations.h"

using namespace std;



int main()
{



    //DynArr<char*> testarr;
    //std::string str = "meisam";
    //testarr.Add(&str[0]);
    //std::string str2 = "food";
    //testarr.Add(&str2[0]);
    //testarr.Add(&a[0]);


    ////testarr.Print();
    //insertionsort(testarr);
    //testarr.Print();

    DynArr<int> myArr;
    myArr.Add(76); myArr.Add(8); myArr.Add(0); myArr.Add(21); myArr.Add(15); myArr.Add(91); myArr.Add(6); myArr.Add(2);
    myArr.Print();
    mergesort(myArr, 0, myArr.Size() - 1);
    myArr.Print();

    return 0;
}