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

// struct Employee {
//     std::string name; 
//     int salary; 
// };

// int main()
// {
//     Employee* pEmp = NULL;
//     pEmp = new Employee; 

//     // access using arrow operator NOT dot operator
//     pEmp -> name = "mostafa"; 
//     pEmp -> salary = 150; 

//     delete pEmp; 
// }

// Fith example: sorting struct array based on specific criterea

// struct Employee{
//     std::string name; 
//     int salary; 
//     int position; 
// };

// // Writing wrong function may cause RTE
// // When return true, means first object must come before second object
// // if we called cmp(A, B) and returned true, NEBER have cmp(B, A) = true
// // If A == B, then both cmp(A, B) and cmp(B, A) MUST give false

// bool cmp(const Employee & first, const Employee &second)    // compare function
// {   // The right comparison should be field by field based on YOUR priority

//     // if first field NOT equal, then it determines the answer
//     if(first.salary != second.salary)
//         // Let bigger salary be preferred
//         return first.salary > second.salary; 

//     // Now same salary, name to name
//     if(first.name != second.name)
//         return first.name < second.name; 
    
//     // Now, the remaining is the position. DIRECTLY compare here. No if codition
//     return first.position < second.position; 
// }

// int main()
// {
//     Employee emps[5] = {
//         {"baher", 70, 5}, {"zyad", 99, 10}, {"ali", 70, 2}, 
//         {"baher", 70, 5}, {"baher", 70, 3} 
//     };

//     // cmp function: Let sort based on, bigger salary, 
//         // if tie smaller name, if tie smaller position
//     std::sort(emps, emps + 5, cmp); 

//     for(int i{0}; i < 5; ++i){
//         Employee & emp = emps[i];
//         std::cout << emp.salary <<" " << emp.name << " " << emp.position <<"\n"; 
//     }
// }


// Offtopic : Pointer to function

int sum(int n, int m)
{
    return n + m; 
}

int mul (int n, int m)
{
    return n * m; 
}

// pointer to function that takes two integers
int (*functionPtr)(int, int); 

int compute(int a, int b, int (*functionPtr)(int, int))
{
    return (*functionPtr)(a, b); 
}

int main()
{
    functionPtr = &sum; // address of function
    int val = (*functionPtr)(2, 5); 

    val = compute(2, 5, mul); 

    // array of pointers to function
    int (*p[2]) (int x, int y); 
    p[0] = sum; 
    p[1] = mul; 
    val = (*p[0])(3, 2); 
}