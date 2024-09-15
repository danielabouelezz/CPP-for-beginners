#include <iostream>
#include <assert.h>

bool lessThan(const std::string ex1, const std::string ex2)
{ 
    if(ex1 == ex2)
    {
        std::cout<<ex1<<"\n";
        assert(false);
    }
    return ex1 < ex2? true : false;
}

int main()
{
    bool result = lessThan("aaa", "aaaa");
    std::cout<<result<<std::endl;
}