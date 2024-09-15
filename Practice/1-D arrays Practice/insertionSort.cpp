#include <iostream>
#include <algorithm>
#include <assert.h>

void insertionSort(int* arr, int n)
{
    // start from 1

    for(int i{1}; i < n; ++i)
    {
        int copy = arr[i];
        int j = i-1;

        // find correct position for copy / SHIFT in same time
        for(; j >= 0; --j)
        {
            if(arr[j] < copy)
                break;
            arr[j+1] = arr[j]; //shift 
        }
        arr[j+1] = copy;
    }
}

void TEST_sort()
{
    const int SIZE = 3;
    int arr[SIZE];
    int copy[SIZE];
    int temp[SIZE];

    for(int test = 0; test < 1000; ++test)
    {
        std::cout<<"TEST "<<test + 1<<"\n"<< std::flush;
        //Build random array
        for(int i{0}; i < SIZE; ++i)
        {
            // rand() return random values in range (0, RAND_MAX = 32767)
            temp[i] = copy[i] = arr[i] = rand() % 100;
        }
        insertionSort(arr, SIZE);

        std::sort(copy, copy + SIZE);

        bool passed = true;
        for(int i{0}; i < SIZE; ++i)
            passed &= (arr[i] == copy[i]);

        if(!passed)
        {
            for(int i{0}; i < SIZE; ++i)
                std::cout<<temp[i] <<" "<< std::flush;
            assert(false);
        }
    }
    std::cout<<"\nPerfect\n";
}

int main()
{
    TEST_sort();
}