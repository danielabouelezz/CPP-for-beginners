/*
a passed by value .. Caller don't feel changes
b passed by reference .. Caller feel its changes
*/
#include <iostream>

void f(int a, int& b)
{
    std::cout<<a<<" "<<b<<"\n";
    ++a; ++b;
}

int main()
{
    int x = 1, y = 1;
    f(x, y);
    f(x, y);
    f(x, y);
    return 0;
}
/* Output:
1 1
1 2
1 3
*/