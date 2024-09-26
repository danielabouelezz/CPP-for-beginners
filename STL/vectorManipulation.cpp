#include <bits/stdc++.h> 

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)v.size())

typedef std::vector<int> vi;

void printVec(vi v, const std::string st)
{
    std::cout<<st<<" ";
    vi::iterator it = v.begin();
    while(it != v.end())
    {
        std::cout<<(*it)<<" ";
        ++it;
    }
    std::cout<<"\n";
}

bool isOdd(int n) { return n%2 != 0;}

// In fact lots of these examples are applicable to any 
// thing that has iterators (e.g. strings)
void vectorManipulation()
{
    const int length = 10;
    int array[length] = {4, 2, 3, 2, 9, 2, 18, 17, 20};
    vi v1(array, array + length);
    vi v2(v1.begin()+2, v1.begin()+5);

    printVec(v1, "V1: ");
    printVec(v2, "V2: ");

    // Distance between 2 iterators = Equal the substraction
    // of both iterators(e.g it2 - it1, where it2 is bigger)
    std::cout<<"distance: "<<std::distance(v1.begin(), v1.begin() +3)<<"\n";
    std::cout<<"distance: "<<std::distance(v2.begin() +4, v2.begin())<<"\n";

    vi::iterator it; 

    vi v3 = v1; //copy
    replace(all(v3), 2, 7); //replace each index that has the value of 2 by 7
    printVec(v3, "V3: ");

    replace_if(all(v3), isOdd, 17);
    printVec(v3, "V3: ");

    // Search for 3 consecutive elements with value 20
    it = search_n(all(v3), 3, 17);

    if(it != v3.end())
        std::cout<<"3 Consecutive 17s from index: "<<it-v3.begin()<<"\n";

    // Searching for subvector
    it = search(all(v1), all(v2));
    if(it != v1.end())
        std::cout<<"The sub-vector from index: "<<it - v1.begin()<<"\n";

    // Some methods need the array to be sorted before we can use them for example: 
    // unique/ binary_search/ lower_bound/ upper_bound
    sort(all(v1));
    printVec(v1, "V1: ");

    bool ans = binary_search(all(v1), 17); // v1 must be sorted first - O(logn)
    std::cout<< "Searching for 17: "<<ans <<"\n";

    // Finds the first element greater than or equal to a given value
    it = lower_bound(all(v1), 16);

    if(it != v1.end())
        std::cout<<"First element >= 16 is "<<*it<<"\n";
    
    //Finds the first element greater than a given value
    it = upper_bound(all(v1), 17);
    
    if(it != v2.end())
        std::cout<<"First element > 17 is "<<*it<<"\n";

    // Return iterator to last element of unique sorted array
    v1.resize(unique(all(v1)) - v1.begin());
    printVec(v1, "Removing duplicates: ");

    // Set_intersection/ set_difference/ set_union/ set_symmetric_difference 
    // must applied on sorted array aswell
}

int main()
{
    vectorManipulation();
}