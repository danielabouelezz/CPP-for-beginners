/* Find how many X, Y numbers such that:
    X in range [1-100]
    Y in range [70-200]
    X < Y
    (X + Y) divisble by 7
*/

#include <iostream> 

int main()
{
    int count{0};

    for(int x{1}; x <= 100; ++x)
    {
        int y{70};

        for(int y = (x >= 70? x+1 : 70); y <= 200; ++y)
        {
            if(x < y && (x+y) % 7 == 0)
            {
                ++count;
            }
        }
    }
    std::cout<<count;

    return 0;
}