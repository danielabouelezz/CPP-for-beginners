#include <iostream> 

template<class type1, class type2>

type1 maximum(type1 a, type2 b)
{
    return a > b? a : b;
}

int main()
{
    std::cout<< maximum(1, 2.2)<<"\n";//2
    std::cout<< maximum(4, 6) <<"\n";//6
    std::cout<< maximum(2.3, 5.6)<<"\n";//5.6
    std::cout<< maximum(2, 3.5) <<"\n";//3
    std::cout<< maximum<int>(3.5, 5)<<"\n";//5
    std::cout<< maximum<double, int>(3.5, 5)<<"\n";//5.0

    return 0;
}