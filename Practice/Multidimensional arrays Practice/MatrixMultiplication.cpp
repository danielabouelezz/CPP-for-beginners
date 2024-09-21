#include <iostream> 
#include <assert.h>

const int Rows1 = 2;const int Cols1 = 3;
const int Rows2 = 3;const int Cols2 = 2;

void matrixMultiplication(int arr1[Rows1][Cols1], int arr2[Rows2][Cols2], int result[Rows1][Cols2])
{
    assert(Cols1 == Rows2);

    for(int r = 0; r < Rows1; ++r)
    {
        for(int c = 0; c < Cols2; ++c)
        {
            result[r][c] = 0;
        }
    }

    for(int i{0}; i < Rows1; ++i)
    {
        for(int j{0}; j < Cols2; ++j)
        {
            for(int k{0}; k <Cols1; ++k)
            {
                result[i][j] += arr1[i][k] * arr2[k][j];
            }
        }
    }
}

int main()
{
    int arr1[Rows1][Cols1] = {{1, 2, 3},
                              {4, 5, 6}
                              };
    int arr2[Rows2][Cols2] = {{7, 8},
                              {9, 10},
                              {11, 12}};
    int result[Rows1][Cols2];
    matrixMultiplication(arr1, arr2, result);

    for(int i{0}; i < Rows1; ++i)
    {
        std::cout<<"\n";
        for(int j{0}; j < Cols2; ++j)
            std::cout<<result[i][j] <<" ";
    }
}