// inline: Don't create actual function. Copy code to caller
//          in compile time
#include <iostream>

inline int maximum(int a, int b)
{
    return a > b? a : b;
}

int main()
{
    // These following cout statements are the same because
    // we used inline.
    std::cout<<maximum(2, 4)<<"\n";
    std::cout<<(2 > 4? 2 : 4) <<"\n";

    return 0;
}

// Use inline only with: 
// 1- very short mehtods
// 2- called many times