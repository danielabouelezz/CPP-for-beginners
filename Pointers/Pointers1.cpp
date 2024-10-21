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

void print(int* arr)
{
    for(int i{0}; i < 5; ++i)
    {
        std::cout<<*(arr + i)<<" "; 
    }
    std::cout<<"\n"; 
}
void pointers_Arithmatic()
{
    int arr[5] = {10, 20, 30, 40, 50}; 
    int* ptr = arr + 2; // Point to 3rd element, 30. 
    int val; 

    std::cout<< ptr - arr <<"\n"; // we can subtract => 2

    val = *ptr++; // use pointer value in val, then increment pointer address
    print(arr);     // 10 20 30 40 50
    std::cout<<val<<" "<<ptr - arr<<"\n"; // 30 3

    ptr = arr + 2; // point to 3
    val = *++ptr; // increment pointer address, then use pointer value in val
    print(arr);  // 10 20 30 40 50 
    std::cout<<val<<" "<< ptr - arr <<"\n"; // 40 3

    ptr = arr + 2; // point to 3
    val = *ptr--; // use pointer value in val, then decrement pointer address
    print(arr);  // 10 20 30 40 50
    std::cout<< val << " " << ptr - arr <<"\n"; // 30 1

    ptr = arr + 2; // point to 3
    val = *--ptr; // decrement pointer address, then use pointer value in val
    print(arr);
    std::cout<< val <<" "<< ptr - arr <<"\n"; // 20 1

    ptr = arr + 2; // point to 3
    val = (*ptr)++; // use pointer value in val, then increment ponter Value
    print(arr); // 10 20 31 40 50
    std::cout<<val << " " << ptr - arr <<"\n"; // 30 2

    // ++ precedence > *, we can force precedence by useing () 
}

void pointers_Arithmatic2()
{
    int arr[5] = {10, 20, 30, 40, 50}; 
    int *ptr = arr; 

    while(ptr != arr + 5)   // we can compare
        std::cout<< *ptr++ <<" "; // print and move to next
}

int main()
{
    //declare_initialize(); 
    //pointers_and_arrays();
    //pointers_Arithmatic(); 
    pointers_Arithmatic2(); 
}