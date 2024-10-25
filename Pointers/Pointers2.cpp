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

int main()
{
   // new_delete_operators(); 
   // array_of_pointers(); 
   pointer_to_pointer(); 

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