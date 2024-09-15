#include <iostream> 
#include <algorithm>
#include <assert.h>

int get2ndMax(int* arr, int size)
{
    assert(size >= 2);
    int fsMax = arr[0], secMax = arr[1]; // initially wrong

    if(fsMax < secMax)
        std::swap(fsMax, secMax);

    for (int i{2}; i < size; ++i)
    {
        if(arr[i] > fsMax)
        {
            secMax = fsMax;
            fsMax = arr[i]; 
        }else if(arr[i] > secMax)
            secMax = arr[i];
    }
    return secMax;
}

void TEST_get2ndMax()
{
    const int SIZE = 10;
    int arr[SIZE];

    for(int test{0}; test < 1000; ++test)
    {
        //Build random array
        for (int i{0}; i < SIZE; ++i)
            //rand() return random values in range[0, RAND_MAX = 32767]
            arr[i] = rand()%100; //arr[i] = in range[0, 99]
        
        int myAnswer = get2ndMax(arr, SIZE); 

        std::sort(arr, arr+SIZE); // let's sort array: e.g. now be 1 2 3 4 5
        int correctAnswer = arr[SIZE-2];
        assert(myAnswer == correctAnswer);
    }
    std::cout<<"\nPerfect\n";
}
int main()
{
    TEST_get2ndMax();
    return 0;
}