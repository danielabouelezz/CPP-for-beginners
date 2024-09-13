#include <iostream>

int f1()
{
    int iCount = 1;

    std::cout<<iCount<<"\n";
    ++iCount;
}

int f2()
{
    static int iCount = 1;

    std::cout << iCount<< "\n";
    ++iCount;
}

int main()
{
    f1(); f1(); f1();
    std::cout<<"*****************\n";
    f2(); f2(); f2();
}

/* Output:
1
1
1
*****************
1
2
3
*/