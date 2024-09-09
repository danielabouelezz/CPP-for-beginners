#include <iostream> 
#include <iomanip>

using namespace std;

int main()
{
    cout<< "|"<<setw(20) <<142.1 <<"|\n";
    cout<<"|" <<setw(20) <<setiosflags(ios::left)<<142.1<<"|\n";// |               142.1|
    cout<<"|" <<setw(20) <<setiosflags(ios::scientific)<<142.1<<"|\n";// |142.1               |
    cout<<"|" <<setw(20) <<setiosflags(ios::fixed)<<142.1<<"|\n";// |1.421000e+002       |
    cout<<"|" <<setw(20) <<setiosflags(ios::right)<<142.1<<"|\n";// |142.1               |
    return 0;
}