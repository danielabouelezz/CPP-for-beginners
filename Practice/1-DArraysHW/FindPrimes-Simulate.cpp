#include <iostream> 

void findPrimes(int n)
{
    bool arr[n];
    for(int i{1}; i < n; ++i)
        arr[i] = true;
    
    arr[0] = arr[1] = false;

    for(int i{2}; i < n; ++i)
    {
        int prod{0};
        int j = i;
        while(prod < n)
        {
            prod = i * j;
            if(prod < n)
                arr[prod] = false;
            ++j; 
        }
    }

    int j{2};
    for(int i{2}; i < n; ++i)
    {
        if(arr[i])
            std::cout<<j <<" is prime.\n";
        else
            std::cout<<j <<" is not prime.\n"; 
        ++j;
    }
}

int main()
{
    findPrimes(25);
}