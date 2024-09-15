#include <iostream> 

int convertToInt(std::string& example)
{
    int result{0}; 
    bool isNegative = false;
    int startIndex{0};

    if(example[0] == '-')
    {
        isNegative = true;
        startIndex = 1;
    }

    for(int i = startIndex; i < example.length(); ++i)
    {
        if(example[i] >= '0' && example[i] <= '9')
        {
            result = result*10 + example[i]-'0'; 
        }
        else{
            std::cerr<<"Invalid input: contains non-digit characters."<<std::endl;
            return 0;
        }
    }

    return isNegative? -result : result;
}
int main()
{
    std::string example = "156a";
    int result = convertToInt(example);
    std::cout<<result;
}