#include <iostream> 

using namespace std;

int main()
{
    cout<<"Please Enter 2 integers to get their sum: \n";
    int iNum1, iNum2;
    cin>>iNum1>>iNum2;
    
    if(cin.fail())
    {
        cout<<"Invalid input Got one more trial.\n";
        cin.clear();
        cin.ignore(10000, '\n');//skips to the next new

        cin>>iNum1>>iNum2;
        if(cin.fail())
            cout<<"Again bad input. bye\n";
        else
            cout<<"Sum is: "<<iNum1 + iNum2<<"\n\n";
    }
    else 
        cout<<"Sum is : " <<iNum1 + iNum2<<"\n\n";
}