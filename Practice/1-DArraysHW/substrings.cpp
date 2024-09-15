#include <iostream> 

// Brute force method of printing substrings
void substrings(const std::string word)
{
    for(int i{0}; i < word.length(); ++i)
    {
        for(int j{i}; j < word.length(); ++j)
        {
            std::string temp = "";
            for(int k = i; k <= j; ++k)
            {
                temp += word[k];
            }
            std::cout<<temp<<" ";
        }
    }
}

int main()
{
    substrings("123a");
}