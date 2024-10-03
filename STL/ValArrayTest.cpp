#include <bits/stdc++.h> 

template <class T> 
void printValArray(const std::valarray<T> v, std::string s = "")
{
    std::cout<<s<<" ";
    for(auto e : v)
        std::cout<<e<<" ";
    std::cout<<"\n";
}

void valArrayTest() // if you want to manipulate lots of basic operator, but on group of numbers
{
    int val[] = {1, -2, 3, -4, -5};

    std::valarray<int> v1(val, 5); // in vector we use std::vector v(array, array + length),
                                // in valarray we use std::valarray(array, length)

    std::valarray<int> v2 = abs(v1);

    std::cout<<v2.sum()<<"\n";

    std::valarray<int> v3 = 2 * (v1 + v2);
    printValArray(v3, "V3: ");

    std::valarray<bool> v4 = (v1 == v2);
    std::cout<<v4.min()<<" "<<v4.max()<<"\n";

    double arr[] = {0, 1, 2, 3};
    std::valarray<double> v5(arr, 4);
    printValArray(v5, "V5: ");

    std::valarray<double> v6 = 2.0 * (v5 + 3.0 * v5); // 2.0 Not 2 - same types used, not mixed

    std::cout<<pow(2.0, v5).sum() <<"\n";// 2^4 -1
    std::cout<<pow(v5, 2.0).sum()<<"\n";
    std::cout<<pow(2.5 * v5, v6).sum() <<"\n";
    //std::cout<<pow(v5, 2.5 * v6).sum()<<"\n"; // compile error because the second parameter should be calculated beforehand 

    //other interesting operatioon : slice_array
}

int main()
{
    valArrayTest();
}