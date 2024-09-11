/** In range 1 - 100, count how many numbers that has following property: 
 * Either number is divisble by 4.
 * Or divisible by both 6 and 10.
 **/
#include <iostream>

int main()
{
    int count{0};

    for(int i{1}; i <= 100; ++i)
    {
        if(i % 4 == 0 || (i % 6 == 0 && i % 10 == 0))
        {
            ++count;
        }
    }
    std::cout<<count<<"\n";

    return 0;
}