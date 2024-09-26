#include <iostream>

const int N = 5;
enum dir {Right = 0, Down, Left, Up}; //spiral order
int dir_r[] = {0, 1, 0, -1};
int dir_c[] = {1, 0, -1, 0};

// dir = 0 => dir +1 = 1   => 1%4 = 1
// dir = 1 => dir +1 = 2   => 2%4 = 2
// dir = 2 => dir +1 = 3   => 3%4 = 3
// dir = 3 => dir +1 = 4   => 4%4 = 0 // wrap

void spiral(int arr[N][N], int N)
{
    std::cout<<"Case N = " << N <<": \t";
    int cnt = 0, r = 0, c = 0, steps = N, dir = 0;

    while(cnt < N*N)
    {
        for(int s{0};  s < 4 && cnt <N*N; ++s) //right, down, left, up
        {
            int m = steps -1; // N-1 steps per direction
            if(s == 3) --m;   // Except last direction, N-2

            for(int i{0}; i < m && cnt < N*N; ++i) //move in specific direction
            {
                std::cout<< arr[r][c]<<" ";
                ++cnt, r += dir_r[dir], c += dir_c[dir];  // Move step
            }
            dir = (dir +1)%4;  // change direction - wrap
        }
        std::cout<< arr[r][c]<<" "; // Special handling for last element
        //Notice, our direction is already correct from last loop
        ++cnt, r += dir_r[dir], c += dir_c[dir]; //Move to new (N-2)x(N-2) matrix
        steps -= 2; // 5 => 4 => 2 => 0
    }  
    std::cout<<"\n";
}

int main()
{
    int arr[N][N] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9 ,10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    };

    spiral(arr, 1); // Test boundaries
    spiral(arr, 2); // Test boundaries
    spiral(arr, 3); // Test boundaries
    spiral(arr, 4); // Test even
    spiral(arr, 5); // Test odd
}