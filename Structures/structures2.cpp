#include <bits/stdc++.h>  

struct Employee{
    std::string name; 
    int salary; 

    Employee(int my_salary, std::string my_name){
        std::cout<<"Creating new object\n"; 
        name = my_name; 
        salary = my_salary; 
    }

    ~Employee(){
        std::cout<<"Destroying the object\n"; 
    }

    void print(); 
};

void Employee::print(){
    std::cout<<name <<" has salary : " << salary<<"\n"; 
}

void print()
{
    std::cout<<"Function to say hello \n" ; 
}

int main()
{
    print(); 
    Employee emp (2000, "ali");
    emp.print(); 
    std::cout<<"BYE\n"; 
}