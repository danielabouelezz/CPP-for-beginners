#include <bits/stdc++.h>

// First example

// struct Employee
// {
//     std::string name; 
//     double salary; 
//     std::string address; 
//     std::string email; 
// };

// int main()
// {
//     Employee mostafa; 
//     mostafa.name = "Mostafa Saad Ibrahim"; 
//     mostafa.salary = 10000; 
//     mostafa.address = "Vancover, Canada"; 
//     mostafa.email = "SaadMostafa@gmail.com"; 
// }


// Second example

// int main()
// {
//     struct Employee{
//         std::string name; 
//         double salary; 
//     };

//     Employee IBM_Emp[10]; // create

//     for(int i{0}; i < 10; ++i)  // use
//         std::cin>> IBM_Emp[i].name >> IBM_Emp[i].salary; 
// }


// Third example

// struct Employee{
//     std::string name; 
//     double salary; 
//     int lucky_numbers[3]; 
// };

// void print(Employee &emp)
// {
//     std::cout << emp.name <<" has salary " << emp.salary <<"k. "; 
//     std::cout <<" His lucky numbers: "; 

//     for(int i{0}; i < 3; ++i)\
//         std::cout<< emp.lucky_numbers[i] <<" "; 
//     std::cout<< "\n"; 
// }

// int main()
// {
//     Employee ali = {"ali ahmed", 120.5, {10, 2, 7}}; 

//     print(ali); 
//     // ali ahmed has salary 120.5k. His lucky numbers: 10 2 7
// }

// Fourth example : using pointer

struct Employee {
    std::string name; 
    int salary; 
};

int main()
{
    Employee* pEmp = NULL;
    pEmp = new Employee; 

    // access using arrow operator NOT dot operator
    pEmp -> name = "mostafa"; 
    pEmp -> salary = 150; 

    delete pEmp; 
}