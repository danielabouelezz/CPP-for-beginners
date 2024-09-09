#include <iostream> 
#include <iomanip>

using namespace std;

int main()
{
    cout<< 6 << endl
        << 18 << endl
        << 124 << endl
        << "---\n"
        <<(6 + 18 + 124) <<endl;

    cout<< endl;

    cout<< setw(3) <<6 << endl
        << setw(3) <<18 <<endl
        << setw(3) <<124 <<endl
        << "---\n"
        <<(6 + 18 + 124) <<endl;
}