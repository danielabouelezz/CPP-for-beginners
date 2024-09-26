#include <bits/stdc++.h>

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)(v.size()))

typedef  std::vector<int> vi;

int main()
{
    // vi v1(10);
    // vi v2(10, 7);

    // vi::iterator it = v1.begin();
    // std::vector<int>::iterator it2 = v2.begin();

    // while(it != v1.end())
    // {
    //     std::cout<<(*it)<<(*it2)<<"\n";

    //     ++it, ++it2;
    // }

    //Printing sorted vectors: 

    vi v4(1);
    v4.resize(15);

    vi::iterator it4 = v4.begin(); // using iterator to fill the vector
    //Filling the vector by number values between 1 and 10; 
    while(it4 != v4.end())
    {
        int temp = (int)(rand() % 10 +1);
        (*it4) = temp;
        ++it4;
    }
    std::cout<<"Before sorting: \n";
    for(int i{0}; i < v4.size(); ++i)
    {
        std::cout<<v4[i]<<" ";
    }
    std::cout<<"\n";
    std::cout<<"it4: "<<*it4<<"\n";
    std::sort(v4.begin(), v4.end()); //Sorting in ascending order

    std::cout<<"After ascending sorting: \n";
    for(int i{0}; i < v4.size(); ++i)
    {
        std::cout<<v4[i]<<" ";
    }

    //Sorting in descending order: 
    std::sort(v4.rbegin(), v4.rend());
    std::sort(v4.begin(),v4.end(), std::greater<int>());
    std::cout<<"After descending sorting: \n";
    for(int i{0}; i < v4.size(); ++i)
    {
        std::cout<<v4[i]<<" ";
    }
    std::cout<<"###################################";
    // Find elements in the array: 
    vi v1(10); 
    vi::iterator it = v1.begin();
    while(it != v1.end())
    {
        *it = rand() % 10 + 1;
        ++it;
    }
    if(std::find(all(v1),7) != v1.end())
        std::cout<<"\n 7 in v2\n";
    
    if(std::find(all(v1), 7) == v1.end())
        std::cout<<"\n 7 is not in v2 \n";
}