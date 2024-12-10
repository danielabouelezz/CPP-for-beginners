#include <bits/stdc++.h>  

// struct Employee{
//     std::string name; 
//     int salary; 

//     Employee(int my_salary, std::string my_name){
//         std::cout<<"Creating new object\n"; 
//         name = my_name; 
//         salary = my_salary; 
//     }

//     ~Employee(){
//         std::cout<<"Destroying the object\n"; 
//     }

//     void print(); 
// };

// void Employee::print(){
//     std::cout<<name <<" has salary : " << salary<<"\n"; 
// }

// void print()
// {
//     std::cout<<"Function to say hello \n" ; 
// }

// int main()
// {
//     print(); 
//     Employee emp (2000, "ali");
//     emp.print(); 
//     std::cout<<"BYE\n"; 
// }

struct Employee{
    std::string name; 
    int salary; 

  // Overload operators are functions with special function names
  bool operator == (const Employee &b )
  {
    return name == b.name && salary == b.salary; 
  }

  bool operator < (const Employee& b)
  {
    if( name != b.name){ 
        return name < b.name;
    } 
    return this-> salary < b.salary; // this pointer
  }
};

void print(const Employee* empPtr)
{
    for(int i{0}; i < 5; i++)
    {
        std::cout<<empPtr[i].name << " has salary of: "<< empPtr[i].salary<<"\n"; 
    }
}

int main()
{
    Employee emps[5] = {
        {"baher", 70}, {"zyad", 99}, 
        {"ali", 70}, {"baher", 50}, {"baher", 70} 
    };

    bool comparison1 = emps[0] < emps[3];  
    bool comparison2 = emps[0] == emps[3] ; 
    // bool comparison2 = emps[0] > emps[3]; // we did not define

    std::sort(emps, emps+ 5); // we can now deal as built in types
    print(emps); 
}