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

/*
    Typical backtracking procedure
    void recursion(state s)
    {
        if(base(s))
            return;
        
        for each substate ss
            mark s
        
        recursion(ss)

        unmark ss
    }
 */

// Generate all sequences of given length, of zeros and ones
// E.g. for len = 3: 000, 001, 010, 011, 100, 101, 110, 111
void generateBinary(int len, std::string cur = "")
{
    if(len == 0)
    {
        std::cout<<cur<<"\n";
        return; 
    }

    generateBinary(len -1, cur + "0"); 
    generateBinary(len -1, cur + "1"); 
}

// Generate all sequences of given length, of zeros, ones and twos
// E.g. for len = 2: 00, 01, 02, 10, 11, 12, 20, 21, 22

void generateTernary(int len, std::string cur = "")
{
    if(len == 0)
    {
        std::cout<<cur<<"\n";
        return; 
    }

    generateTernary(len -1, cur + "0");
    generateTernary(len -1, cur + "1");
    generateTernary(len -1, cur + "2");
}

// Pring all possible permutations of numbers 0, 1, 2, .... n-1

void perm(int i, int n, int vis[], int cur[])
{
    if(i == n)
    {
        for(int j{0}; j < n; ++j)
            std::cout<<cur[j];
        std::cout<<"\n";
        return; 
    }

    for(int j = 0; j < n; ++j)  if(!vis[j])
    {
        vis[j] = 1; 
        cur[i] = j; 

        perm(i+1, n, vis, cur); 
        vis[j] = 0; 
    }
}

int main()
{
    // Explanation(5); 
    // int n = Factorial(5);
    // std::cout<<n; 
    // triangle(7);
    // reverseTrianlge(7);
    // std::cout<<F3n_1(22);
    // createGRid(); 
    // int result = maxpathSum(0, 0); 
    // std::cout<<result<<std::endl;
    //generateBinary(3);
    //generateTernary(2);
    /*int vis[100] = {0}; 
    int cur[100] = {0}; 
    perm(0, 5, vis, cur);*/
}