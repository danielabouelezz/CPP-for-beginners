#include <bits/stdc++.h> 

#define all(v) ((v).begin()), ((v).end())


// The return type is find at run time because we used template data type. 
template <class T> std::string toStr(T par) 
{
    std::ostringstream oss; 
    oss << par; 
    return oss.str();
}

void stringBasicTest()
{
    std::string str2("initial2");
    std::string test =  "hi abc abc abc abc";

    std::cout<<test.substr(3) <<"\n"; // abc abc abc
    std::cout<<test.substr(3, 5) <<"\n"; // abc a

    std::cout<< "Mostafa at: " <<test.find("Mostafa") <<"\n";
    std::cout<<"Mostafa at: " <<(int)test.find("Mostafa")<<"\n";

    std::cout<<test.find("abc", 5) <<"\n"; // starting the search at 5th index

    // Functions that searches for a CHARACTER from a given string
    std::cout<<test.find_last_of("cab")<<"\n";
    std::cout<<test.find_first_of("aic")<<"\n";
    std::cout<<test.find_first_of("aic", 4)<<"\n";
    std::cout<<test.find_first_of("aic", 4, 6)<<"\n";
    std::cout<<test.find_first_not_of("aic")<<"\n";

    test.replace(4, 3, "x"); // replace from 4, 3, chars with x

    char array[4] = {'a', 'b', 'c', 'd'};
    std::string t = array; // converts character array into string
    const char* s = t.c_str(); // converts string into character array

    test.erase(4); // remove from position 4 to end of string
    std::cout<<"String: "<<test <<"\n";
    test.erase(4, 6); // remove 6 chars starting in position 4

    ////////////////////////////////////////////////
    std::cout<<toStr(32) <<"\n";

    std::vector<int> v; 
    v.push_back(30); 
    v.push_back(10); 
    v.push_back(7);

    std::ostringstream oss1; 
    copy(all(v), std::ostream_iterator<int> (oss1, ",")); // convert vector to string
    std::cout<< oss1.str() <<"\n";

    std::istringstream iss("10 20 30"); // helps much inreparsing input blocks
    int x;
    while(iss >> x) // same if cin stream
        std::cout<< "Readed x "<<x <<"\n";
}

int main()
{
    stringBasicTest();
}