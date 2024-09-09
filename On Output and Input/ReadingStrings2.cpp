#include <iostream>
#include <iomanip> 

using namespace std;

int main()
{
    cout<<"Enter bar separated data: E.g. ahmed|aly|150\n\n";
    string firstName;
    string secondName;
    double salary;

    getline(cin, firstName, '|');
    getline(cin, secondName, '|');
    
    cin.ignore();
    cin>>salary;

    cout<<firstName<<"\n";
    cout<<secondName<<"\n";
    cout<<salary<<"\n";

    return 0;
}