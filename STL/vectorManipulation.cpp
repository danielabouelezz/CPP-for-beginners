#include <bits/stdc++.h> 

#define all(v) ((v).begin()), ((v).end())
#define sz(v) ((int)v.size())

typedef std::vector<int> vi;

void printVec(vi v, const std::string st = "")
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
bool isEqual(int x, int y) { return x == y;}
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

    v2 = v1; 
    v2.push_back(v2.back());
    v2.push_back(v2.back()+20);
    v2.push_back(v2.back() +7);
    printVec(v2, "V2: ");
    std::vector<int> v;

    set_intersection(all(v2), all(v1), back_inserter(v)); // back_inserter fills the v vector with the intersection
    printVec(v, "Set_intersection: ");
    
    v.clear();
    set_difference(all(v2), all(v1), back_inserter(v));
    printVec(v, "Set_difference: "); // what happens if v1 is proper subset of v2? ans: v is empy.

    v.clear();
    set_union(all(v2), all(v1), back_inserter(v));
    printVec(v, "Set_union: ");

    ////////////////////////////////////////////////////

    int mx = *max_element(v2.begin(), v2.end());
    int mn = *min_element(v2.begin(), v2.end());

    std::cout<< "Maximum: "<< mx<< " Minimum: "<< mn<<"\n";
    printVec(v1, "V1: ");
    printVec(v2, "V2: ");

    swap_ranges(v1.end()-2, v1.end(), v2.begin()); // you could swap from different vectors
    printVec(v1, "Range swaps: ");

    v2.clear();
    v2.push_back(1);
    v2.push_back(3);
    v2.push_back(4);
    printVec(v2, "New v2: ");

    int vecSum = accumulate(all(v2), 0); // return array SUM
    int vecMul = accumulate(all(v2), 1, std::multiplies<int>()); // return array product

    int sumOfProducts1 = inner_product(all(v2), v2.begin(), 0); // inner product: v1[0] * v1[0] + v2[0] * v2[0]...
    int sumOfProducts2 = inner_product(all(v2), v2.begin(), 0, std::plus<int>(), std::multiplies<int>()); // same as above
    int productsOfSum = inner_product(all(v2), v2.begin(), 1, std::multiplies<int>(), std::plus<int>()); // 1 * (v1[0] + v1[0]) * (v2[0] + v2[0])
    // 0, 1, 0 are the initial value for accumulation. 

    std::cout<<"VecSum: "<<vecSum<<" VecMul: "<< vecMul <<" SumOfProducts: "<< sumOfProducts1<<" ProductsOfSum: "<< productsOfSum<<"\n"; 
    
    v1.clear();
    partial_sum(all(v2), back_inserter(v1));
    printVec(v1, "Accumulative array: ");

    v1.clear();
    partial_sum(all(v2), back_inserter(v1), std::minus<int>());
    printVec(v1, "Substracting array: ");


    // Writing to a stream
    std::ostringstream oss1; 
    partial_sum(all(v2), std::ostream_iterator<int>(oss1, " "));
    std::cout<<"Accumulative array in string: " <<oss1.str()<<"\n"; // 27 68 149 the partial accumulation

    printVec(v1, "V1: ");
    printVec(v2, "V2: ");
    adjacent_difference(all(v2) ,v1.begin()); // the difference between each value and the value in the previous index stored in v1
    printVec(v1, "Adjacent_difference: ");

    adjacent_difference(all(v2), v1.begin(), std::plus<int>()); // Each index is the sum of itsel and the previous index
    printVec(v1, "Adjacent_sum: ");
    
    it = adjacent_find(all(v2), isEqual); //  find first 2 adjacent elements who are EQUAL based on equal function
    if(it != v2.end())
        std::cout<< "The 2 adjacent values are: "<< *it <<" " <<*(it +1) <<"\n";

    v2.insert(v2.begin(), 6);
    v2.insert(v2.begin()+3, 6);
    v2.push_back(6);

    printVec(v2, "V2: ");

    std::cout<<"Count of 6: "<<count(all(v2), 6)<<"\n";
    count_if(all(v2), isOdd); //isOdd is a function called for each element in v2

    v2.erase(remove(all(v2), 6), v2.end()); // remove all 6, and preserve order
    printVec(v2, "Remove 6s: ");

    rotate(v2.begin(), v2.begin() +1, v2.end()); // rotate Direction <--
    printVec(v2, "Rotate: ");

    // In case listing all next_permutaion, you must Sort input first
    sort(all(v2)); 
    do{
        printVec(v2, "Perm: ");
    }while(next_permutation(all(v2))); // permutate on any given iterator with compare function
}

int main()
{
    vectorManipulation();
}