#include <bits/stdc++.h> 

// Sometimes, it is low-level optimization, so better time order
// Sometimes, it drop memory by factor of 8! so better memory order
// Sometimes, it make code shorter

/*
    A   B   !A  A&B     A|B     A^B
    0   0   1   0       0       0
    0   1   1   0       1       1
    1   0   0   0       1       1
    1   1   0   1       1       0

X = 1152 = 10010000000
Y = 1428 = 10110010100

X & Y    = 10010000000
X | Y    = 10110010100
X ^ Y    = 00100010100

A ^ B ^ C ^ D = E   For any bit in E with 1, must be odd number of 1s
X ^ 0 = X       X ^ X = 0
(A ^ B ^ C ^ D ^ E) ^ (A ^ B ^ C) = D ^ E

X >> 1   = 1001000000       Equals X/2 
X >> 2   = 100100000        Equals X/4
X << 1   = 100100000000     Equals X*2
X << 2   = 1001000000000    Equals X*4

X = 11010 = 26 = 2^1 + 2^3 + 2^4 = 2 + 8 + 16

X = 11010 = 26  // Last Bit shows Parity :  Even / Odd
X = 11011 = 27  

X % 2 = X & 1 = bit 0

Generally: x % (2 ^ n)  = X & (2 ^ n -1)

Even test
    if (n % 2 == 1)         -> Fails of n is negative
    if( (n & 1) == 1) -> works always
*/

int bitLength(int n)
{
    if(!n) return 1;
    
    return std::floor(std::log2(n)) + 1;
}

// gets the length of bits that forms the number
int countNumBits(int mask)
{
    int ret = 0; 
    if(!mask)   return 1; 

    while(mask)
    {
        mask >>= 1;
        ret++;
    }
    return ret;
}

void printNumber(int n)
{
    if(!n) return; 

    printNumber(n >> 1); 
    std::cout<<(n & 1); 
}

// Let's count bits
int countNumBits1(int mask) // counting the 1 bits
{
    int ret = 0; 
    
    while(mask)
    {
        if(mask & 1)
        {
            ret++; 
        }
        mask >>= 1;
    }
    return ret; 
}

// Get bit
int getBit(int num, int idx)
{
    return ((num >> idx) & 1) == 1;  // 110100, idx = 4 --> 110 & 1 = 0
}

int setBit1(int num, int idx)
{
    return num | (1 << idx); 
}

int setBit0(int num, int idx)
{
    return num & ~(1 << idx); // 110100, idx = 3 --> 110100 & ~000100 = 110100 & 111011
}

int flipBit(int num, int idx)
{
    return num ^ (1 << idx); 
}

// rotate a bit to right. 0000000000000000000011001101110 -> rotate 5 -> 01110000000000000000110011 

int rotate(int num, int idx)
{
    const int bitNum = 32; 

    return num >> idx | num << (bitNum - idx); 
}

int main()
{
    // printNumber(26, countNumBits(26));
    // std::cout<<"\n";
    // std::cout<<countNumBits1(26); 
    int num = rotate(0b0000000000000000000011001101110, 5); 
    printNumber(num); 
}