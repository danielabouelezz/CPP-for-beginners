#include <bits/stdc++.h>

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


int main()
{
    struct Employee{
        std::string name; 
        double salary; 
    };

    Employee IBM_Emp[10]; // create

    for(int i{0}; i < 10; ++i)  // use
        std::cin>> IBM_Emp[i].name >> IBM_Emp[i].salary; 
}