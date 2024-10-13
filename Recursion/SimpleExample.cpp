#include <bits/stdc++.h> 
#include <iomanip> 

void Explanation(int cnt)
{
    if(cnt < 1)     // Base Case
        return;
    
    std::cout<<"This is a recursion.\n";    // Some logic

    Explanation(cnt -1); //Sub-problem - never go to infinity
}

int Factorial(int n)        
{
    if(n <= 1)
        return 1;
    return n * Factorial(n-1);
}

void triangle(int n)
{
    if(n < 1)
        return;
    
    triangle(n -1);

    for(int i{0}; i < n; ++i)
        std::cout<<"*";
    std::cout<<"\n";
}

void reverseTrianlge(int n)
{
    if(n < 1) 
        return ;
    
    for(int i{0}; i < n; ++i)
        std::cout<<"*"; 
    std::cout<<"\n";

    reverseTrianlge(n-1);
}

// 3n + 1 series: Next(n): if n is odd then n = 3 * n +1. if n is even then n = n / 2. if n == 1, stop.
// E.g. 22 11 34 17 52 26 ...
// Given n , find length of 3n + 1 sequence. E.g. F3n_1(22) = 16

int F3n_1(int n)        // Recursion State: n
{
    if(n == 1)
        return 1;

    if(n % 2 == 0)
        return 1 + F3n_1(n/2);

    return 1 + F3n_1(3*n + 1);
}

const int Max = 10; 
int grid[Max][Max]; 

void createGRid()
{
    for(int i{0}; i < Max; ++i)
    {
        for(int j{0}; j < Max; ++j)
            {
                grid[i][j] = rand()%100; 
            }
    }
}

bool valid(int r, int c) 
{
    return r >= 0 && r < Max && c >= 0 && c < Max; 
}

int maxpathSum(int r, int c)
{
    if(!valid(r, c))
        return 0;
    
    if(r == Max -1 && c == Max-1)
        return grid[r][c]; 
    
    int path1 =  maxpathSum(r+1, c);
    int path2 =  maxpathSum(r, c+1); 

    return grid[r][c] + std::max(path1, path2); 
}

int main()
{
    // Explanation(5); 
    // int n = Factorial(5);
    // std::cout<<n; 
    // triangle(7);
    // reverseTrianlge(7);
    // std::cout<<F3n_1(22);
    createGRid(); 
    int result = maxpathSum(0, 0); 
    std::cout<<result<<std::endl;
}