#include <iostream>
#include <sstream> 

using namespace std;

int main()
{
    string data = "10 mostafa 5.7";

    int iNum;
    string name;
    double dNum;

    istringstream iss(data);

    iss>>iNum>>name>>dNum;

    cout<<iNum<<"\n";
    cout<<name<<"\n";
    cout<<dNum<<"\n";

    return 0;
}