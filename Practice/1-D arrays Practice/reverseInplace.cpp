#include <iostream> 
#include <assert.h>

void reverseInplace(int* arr, int SIZE)
{
    //In-place algorithm: only use some constants..don't create new arrays
    //e.g. don't create new array..copy data reversed to it
    //change in the given array itself

    //idea..swap indices: (1st, last) (2nd, 2nd last)...
    for(int i{0}; i < SIZE/2; ++i)
    {
        std::swap(arr[i], arr[SIZE-i-1]);
    }
}

void print(int* arr, int SIZE)
{
    for(int i{0}; i < SIZE; ++i)
    {
        std::cout<<arr[i]<<" ";
    }
    std::cout<<"\n";
}

// int* createArr(int SIZE)
// {
//     //This function create a random array between 0 - 99
//     int* arr = new int[SIZE]; //allocating memory for the array

//     for(int i{0}; i < SIZE; ++i)
//     {
//         arr[i] = rand() % 100;
//     }

//     return &arr[0];
// }

void TEST_reverseInplace()
{
    const int SIZE = 7;
    int arr[SIZE]; 
    int test[SIZE];

    int usedSize = SIZE;

    for(int k{0}; k < 2; ++k)
    {
        for(int i{0}; i < 1000; ++i)
        {
            for(int j{0}; j < usedSize; ++j)
            {
                int temp = rand() % 100; 
                arr[j] = temp;
                test[j] = temp;
            }

            reverseInplace(arr, usedSize);

            for(int j{0}; j < usedSize; ++j)
            {
                assert(test[j] == arr[usedSize - j -1]);
            }
        }
        --usedSize;
    }
    std::cout<<"\nPerfect\n";
}

int main()
{
    // int SIZE = 4;
    // int* arr = createArr(SIZE);

    // print(arr, SIZE);
    // reverseInplace(arr, SIZE);
    // print(arr, SIZE);

    // delete[] arr; //Free dynamically allocated memory

    TEST_reverseInplace();
}