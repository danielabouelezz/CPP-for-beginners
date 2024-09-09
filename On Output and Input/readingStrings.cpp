#include <iostream> 
#include <iomanip> 

using namespace std;

int main()
{
    string firstName, secondName; 
    string line1, line2; 

    cin >> firstName>>secondName;
    cout<<"Entered name: "<<firstName<<" "<< secondName <<"\n\n";

    getline(cin, line1); //read the entered string.

    getline(cin, line1);
    cout<<"Line1 data: "<<line1<<"\n\n";

    getline(cin, line2);
    cout<<"Line2 data: "<<line2<<"\n\n";

    return 0;
}