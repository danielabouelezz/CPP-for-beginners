#include <iostream> 

int max(int a, int b)
{
    return a > b ? a : b;
}

double max(double a, double b)
{
    return a > b ? a : b;
}

int main()
{
    std::cout<< max(2, 4)<<"\n";
    std::cout<< max(2.6, 4.7)<<"\n";

    return 0;
}