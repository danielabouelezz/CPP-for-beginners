#include <iostream> 

void printGroups(const std::string example)
{
    int subGroupSize{1};
    char indexContent = example[0];
    std::string temp = "";
    for(int i{1}; i < example.length(); ++i)
    {
        if(example[i] != example[i-1])
        {
            for(int j{0}; j < subGroupSize; ++j)
                temp += indexContent;
            std::cout<<temp<<"\n";
            temp = "";
            subGroupSize = 0;
            indexContent = example[i];
        }
        
        ++subGroupSize;
        if(i == example.length() -1)
        {
            for(int j{0}; j < subGroupSize; ++j)
                temp += indexContent;
            std::cout<<temp<<"\n";
        }
    }
}

int main()
{
    printGroups("HHH");
    return 0;
}