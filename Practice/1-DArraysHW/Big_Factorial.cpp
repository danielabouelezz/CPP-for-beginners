#include <iostream> 
#include <vector>

void calculate(int n)
{
    std::vector<int> result;
    result.push_back(1);

    for(int j = 2; j < n; ++j)
    {
        int carry{0};
        for(int i{0}; i < result.size(); ++i)
        {
            int prod = result[i] * j + carry;
            result[i] = prod % 10;
            carry = prod / 10; 
        }        

        while(carry)
        {
            result.push_back(carry % 10);
            carry /= 10;
        }
    }

    std::cout<< n << "! = ";
    for(int i = result.size() -1; i >= 0; --i)
    {
        std::cout<<result[i];
    }
    std::cout<<"\n";
}

int main()
{
    calculate(100);
}