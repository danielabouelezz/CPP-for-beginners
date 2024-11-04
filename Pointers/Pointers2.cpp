#include <bits/stdc++.h> 

// **New** allows us to create dynamically array in memory
// and **Delete** to release this memory
void new_delete_operators()
{
    int num_employee; 
    std::cin>> num_employee; 

    int* employee_salaries = new int[num_employee]; 
        // Old style: int employee_salaries[1000]; 

    // Use employee_salaries as if it is normal array
    for (int i{0}; i < num_employee; ++i)
        std::cin>>employee_salaries[i]; 
    
    // Use the array in some processing
    delete[] employee_salaries; 

    float* pFloat = new float; 
    *pFloat = 10.5; 
    std::cout<< pFloat <<" "<< *pFloat <<"\n"; 

    delete pFloat; 
}

void array_of_pointers()
{
    int arr2d[3][2]; 
    int* arr[3] = {0}; // array of 3 pointers - initialized to NULL

    for (int i{0}; i < 3; ++i)
        arr[i] = new int[2]; // Pointer to 2 elements

    // Now use the arr as if 3x2 matrix
    for(int i{0}; i < 3; ++i)
        for(int j{0}; j < 2; ++j)
            arr[i][j] = arr2d[i][j] = i*2+j; 

    for(int i{0}; i < 3; ++i)
        delete[] arr[i]; 
}

void print(int **arr) // pass as parameter
{
    for(int i{0}; i < 3; ++i)
    {
        for(int j{0}; j < 2; ++j)
            std::cout<< arr[i][j] <<" "; 
        std::cout<<"\n"; 
    }
}

int** create() // return as parameter
{
    int** ptr2d = new int*[3]; 
    for(int i{0}; i < 3; ++i)
    {
        ptr2d[i] = new int[2]; 

        for(int j{0}; j < 2; ++j)
            ptr2d[i][j] = (i + 1)*(j + 1); // assign
    }
    return ptr2d;
}

void free(int** arr)
{
    for(int i{0}; i < 3; ++i)
        delete[] arr[i]; 
    delete[] arr; 
}

void pointer_to_pointer()
{
    int** ptr2d = create(); 
    print(ptr2d); 
    free(ptr2d); 
}

// Commion Mistakes

int buggyPointers(int a, int b)
{
    int* ptr1 = new int[8], *ptr2 = new int[8], *ptr3 = new int[8]; 
    int* salary; // bad practice => garbage
    int* grade = NULL; // best practice

    if(a == 0) return 1; // Forget to release memory => leak

    delete ptr1; // Wrong, it should be delete[]
    ptr1 = NULL; // best practice; 

    int* ptr = ptr2; 
    ++ptr; // move to next memory position
    delete []ptr; // wrong, delete from array start

    delete []ptr3; 
    ptr3[2] = 5; // Wrong, memory deleted!
    delete []ptr3; // Wrong, double free problem 

    delete grade; // It is NULL, no problem/benefit
    *grade = 10; // Wrong, it is not initialized
    grade = new int; // one element
    delete[] grade; // Wrong, should be delete NOT delete[]
    
    return a*b; 
}

// Passing arrays/pointers
    // test 1, 2, 3 are actually SAME for compiler
void test1(int arr[]){} // pointer to an element
void test2(int arr[5]){} // pointer to an element
void test3(int *ptr){} // pointer to an element
void test4(int(&arr)[5]){} // pointer to an array, Force array of size 5

void passingArrays_Pointers()
{
    int arr[] = {1,2,3,4,5}; 
    int* ptr = arr; 

    test1(arr); 
    test2(arr);
    test3(arr); 
    test4(arr); 

    int x = 10; 
    test2(&x); 

    // test4(&x); 
    // test4(ptr); 
    test4(arr); 

    int arr2[3] = {1, 2, 3}; 
    // test4(arr2); 
}

// Shooting yourself in the foot

void shootingYourselfInTheFoot()
{
    const int SIZE = 10; 
    int arr[SIZE]; // Good - Fixed size

    int n = 20; 
    int arr2[n]; // Variable size - NOT standard - Dont't use

    // Don't cast between primitives .. unless you know what you really do
    short shortVal1 = 1; 
    int* pIntPtr1 = (int*)&shortVal1; 
    *pIntPtr1 = 2147483647; // Corrupt memory, change in 4 bytes not 2
    std::cout<< *pIntPtr1 <<"\n"; // may crach now

    // Don't get part of the memory!
    // This is true for little endian but not big endian!
    int value = 770; // 11 00000010
    char secondByte = *(((char*)&value)+1); // right way using buts (later)
    std::cout<<(int)secondByte <<"\n"; // 3 on Intel x86 processor (little endian)

    // Don't use C syle case - No compiler time checking
    // Use static case
    // int* pIntPtr2 = static_cast<int*>(&shortVal1); Compiler error
}

int main()
{
   // new_delete_operators(); 
   // array_of_pointers(); 
   pointer_to_pointer(); 
   // --- See common pointers mistake in function "buggyPointers()"
   // --- See mistakes in the usage of C++ in function "shootingYourselfInTheFoot()"

}

// MEMORY LEAKS
/*
    -The worst thing happens in real life is memory leak
    -Forget or do buggy code that doesn't free memory
    -Imagine function each time is called creates 10^6
     numbers but don't free
    -Each time is called, memory grow up
    -Then machine stuck => whole memory reserved
    -Some tools in real life to detect leaks helps
    -Revise your code very well
    -Check task manager memory of process
    -Or use nowadays smart pointers(out of scope for this course). 
*/