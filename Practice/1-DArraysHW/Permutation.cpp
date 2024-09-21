#include <iostream> 

void Permutation(int* arr1, int* arr2, int Size)
{
    bool isVisited[Size] = {false}; 

    int Start{0};
    int index = arr2[Start];

    while(true)
    {
        while(isVisited[index])
        {
            index = arr2[++Start];
            if(Start >= Size)
                break;
        }
        if(Start >= Size)
            break;

        isVisited[index] = true;
        int value = arr1[index];
        std::cout<<index<<" -> "<< value<<"\n";
        index = value;
    }
}


int main()
{
    int arr1[] = {2, 0, 1, 4, 3, 5};
    int arr2[] = {0, 1, 2, 3, 4, 5};
    Permutation(arr1, arr2, sizeof(arr1)/sizeof(arr1[0]));
}

/* This program will output : 
0 -> 2
2 -> 1
1 -> 0 // End of cycle

3 -> 4
4 -> 3 // End of cycle

5 -> 5
*/