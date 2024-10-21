#include <bits/stdc++.h> 

void declare_initialize() 
{
    int val = 5; 
    int* ptr = &val; 

    std::cout<<val<<"\n"; 
    std::cout<<&val<<"\n"; 
    std::cout<<*ptr<<"\n"; // dereferencing ptr
    std::cout<<ptr<<"\n"; 
    std::cout<<&ptr<<"\n"; 
}

void pointers_and_arrays()
{
    int arr[5] = {8, 6, 2, 4, 3};

    // compiler creates an internal POINTER for and stores the array's starting address
    std::cout<<arr<<"\n";   // address of array
    std::cout<<&arr[0]<<"\n"; //  get address of 1st value

    // int* pArr = arr[0]; // Wrong, arr[0] is not address
    int* pArr = &arr[0]; // Point to 1st element. 
        // We can do also: int* pArr = arr; 
    
    std::cout<<*pArr<<"\n"; // 8
    std::cout<<pArr <<"\n"; // address of array and first element of array
    std::cout<<&pArr <<"\n"; // address of the pArr pointer itself

    for(int i{0}; i < 5; ++i)
    {
        // All following Same value
        std::cout<<arr[i]<<" "; // normal array usage
        std::cout<<pArr[i]<<" "; // use it as if an array
        std::cout<<*(arr + i)<< " "; // Move i integers from arr, and get value
        std::cout<<*(pArr + i) <<" "; // change address => dereference value
            // *(pArr + i) NOT same as *pArr + i
        std::cout<<"\n" ; 
    }

    pArr++; 
    std::cout<<*pArr<<"\n"; // We can increment pointer => 6
    //arr++; // COMPILE ERROR
}
int main()
{
    //declare_initialize(); 
    pointers_and_arrays();
}