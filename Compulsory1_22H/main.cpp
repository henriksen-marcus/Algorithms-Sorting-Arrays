#include "declarations.h"

using namespace std;



int main()
{

    

   // myArr.Print();

    //int a = 14;
    //std::cout << (a >> 1);
    string a = "das";

    DynArr<char*> testarr;
    std::string str = "meisam";
    testarr.Add(&str[0]);
    std::string str2 = "food";
    testarr.Add(&str2[0]);
    testarr.Add(&a[0]);


    //testarr.Print();
    insertionsort(testarr);
    testarr.Print();


    return 0;
}


