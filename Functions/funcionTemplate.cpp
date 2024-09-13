#include <iostream> 

template<class type> 

type maximum(type a, type b)
{
    return a > b? a : b;
}

int main()
{
    std::cout<<maximum(2, 4)<<"\n";
    std::cout<<maximum(2.0, 6.1)<<"\n";

    return 0;
}