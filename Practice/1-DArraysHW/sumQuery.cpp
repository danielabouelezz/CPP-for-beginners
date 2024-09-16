#include <iostream> 

bool notValid(int start, int end, int size)
{
    if(start < 0 || end >= size || end < start)
        return true;
    return false;
}
int sumQuery(int start, int end, int* arr, int size)
{
    if(notValid(start, end, size))
    {
        std::cout<<"The range chosen is not valid. ";
        return -1;
    }
    int sum{0};
    for(int i{start}; i <= end; ++i)
    {
        sum += arr[i];
    }
    return sum;
}

int main()
{
    int arr[] = {1, 2, 5, 0, 4};
    std::cout<<sumQuery(0, 1, arr, 4);
}