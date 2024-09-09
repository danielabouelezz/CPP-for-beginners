#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    cout<<"Enter either National security number or Full Name as your identifier\n";

    string line;
    getline(cin, line);

    istringstream iss1(line);

    int iNum;
    iss1>>iNum;

    if(iss1.fail())
        cout<<"It was string. \n\n";
    else
        cout<<"It was number.\n\n";
    
    return 0;
}