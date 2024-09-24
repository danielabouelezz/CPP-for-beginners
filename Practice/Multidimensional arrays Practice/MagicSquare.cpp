//Finding if the givin 2-D array is a magic square which means
// that the sum of any row, sum of any column and sum of any of the 2 
// diagonals is the SAME.
//P.S: these are square 2-D arrays(Rows = Columns)
#include <iostream> 
#include <assert.h>

const int Size = 3;

// In this code we will be checking if the sum of the rows, cols
// or diagonals of the 2-D matrix are the same. 
// If so the matrix is called a magic Square. 
bool magicSquare(int arr[Size][Size], int Size)
{
    int sumRow{0}, sumCol{0}, sumDiag1{0}, sumDiag2{0};
    int doneDiag{0};
    int diag1{0}, diag2 = Size -1;

    for(int i{0}; i < Size; ++i)
    { 
        if(sumRow != sumCol || sumRow != sumDiag1 || sumDiag2 != sumDiag1)
        {
            std::cout<<"This is not a magic square\n";
            return false;
        }

        sumRow = sumCol = 0;

        for(int j{0}; j < Size; ++j)
        {
            sumRow += arr[i][j];
            sumCol += arr[j][i];
            if(!doneDiag)
            {
                for(int j{0}; j < Size; ++j)
                {
                    sumDiag1 += arr[diag1][j];
                    sumDiag2 += arr[diag2][j] ;
                    ++diag1, --diag2;
                }
                doneDiag = 1;
            }
        }
    }
    std::cout<<"This is a magic square"<<"\n";
    return true;
}

int main()
{
    int arr[Size][Size] = {{8, 1, 6},
                          {3, 5, 7},
                          {4, 9, 2}};
    magicSquare(arr, Size);                    
}