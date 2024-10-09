#include <bits/stdc++.h> 

void Explanation(int cnt)
{
    if(cnt < 1)     // Base Case
        return;
    
    std::cout<<"This is a recursion.\n";    // Some logic

    Explanation(cnt -1); //Sub-problem - never go to infinity
}

int main()
{
    Explanation(5); 
}