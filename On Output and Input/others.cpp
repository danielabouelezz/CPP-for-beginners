#include <iostream>
#include <iomanip> 

using namespace std;

int main()
{
    bool status = true;
    cout<<status<< "\n";
    cout<<boolalpha<<status<<"\n";
    cout<<"some input" <<flush<<"\n"; // flush forces the output to be shown even if there's a crash.

    return 0;
}