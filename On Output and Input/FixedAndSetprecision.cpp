#include  <iostream> 
#include <iomanip> 

using namespace std;

int main()
{
    double a = 2; 
    double b = 2.5; 
    double c = 2.958123456;

    cout<< a << "\n"; // 2
    cout<< b << "\n"; // 2.5 
    cout<< c << "\n"; //2.95812

    cout<< fixed <<setprecision(3)<<a << "\n"; // 2.000
    cout<< fixed <<setprecision(3)<<b <<"\n"; // 2.500
    cout<< fixed <<setprecision(3) << c<<"\n"; // 2.958 // setprecision round the last number
    cout<<setw(1) <<fixed <<setprecision(3) <<c<<"\n\n"; // 2.958 // setw is ignored here

    cout<<a <<"\n"; //2.000
    cout<<b<<"\n";// 2.500
    cout<<c<<"\n";// 2.958
    //The re-displayed a , b and c will be shown as their last format. 
    return 0;
}