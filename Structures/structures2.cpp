#include <bits/stdc++.h>  

struct Employee{
    std::string name; 
    int salary; 

    void SetSalary(int value)   // Method NOT Function
    {
        salary = value; 
    }

    void AddSalary(int value); 
};

void Employee::AddSalary(int value) // We can define method outside too
{
    salary += value; 
}

int main()
{
    Employee emp; 
    std::cout<<emp.salary <<"\n";   //garbage, you may be lucky and get zero

    emp.SetSalary(100); 
    std::cout<<emp.salary<<"\n";    //100

    emp.AddSalary(25); 
    std::cout<<emp.salary<<"\n";    // 135
}