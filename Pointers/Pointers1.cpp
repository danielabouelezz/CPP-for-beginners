#include <bits/stdc++.h> 

void declare_initialize() 
{
    int val = 5; 
    int* ptr = &val; 

    std::cout<<val<<"\n"; 
    std::cout<<&val<<"\n"; 
    std::cout<<*ptr<<"\n"; // dereferencing ptr
    std::cout<<ptr<<"\n"; 
    std::cout<<&ptr<<"\n"; 
}

void pointers_and_arrays()
{
    int arr[5] = {8, 6, 2, 4, 3};

    // compiler creates an internal POINTER for and stores the array's starting address
    std::cout<<arr<<"\n";   // address of array
    std::cout<<&arr[0]<<"\n"; //  get address of 1st value

    // int* pArr = arr[0]; // Wrong, arr[0] is not address
    int* pArr = &arr[0]; // Point to 1st element. 
        // We can do also: int* pArr = arr; 
    
    std::cout<<*pArr<<"\n"; // 8
    std::cout<<pArr <<"\n"; // address of array and first element of array
    std::cout<<&pArr <<"\n"; // address of the pArr pointer itself

    for(int i{0}; i < 5; ++i)
    {
        // All following Same value
        std::cout<<arr[i]<<" "; // normal array usage
        std::cout<<pArr[i]<<" "; // use it as if an array
        std::cout<<*(arr + i)<< " "; // Move i integers from arr, and get value
        std::cout<<*(pArr + i) <<" "; // change address => dereference value
            // *(pArr + i) NOT same as *pArr + i
        std::cout<<"\n" ; 
    }

    pArr++; 
    std::cout<<*pArr<<"\n"; // We can increment pointer => 6
    //arr++; // COMPILE ERROR
}

void print(int* arr)
{
    for(int i{0}; i < 5; ++i)
    {
        std::cout<<*(arr + i)<<" "; 
    }
    std::cout<<"\n"; 
}
void pointers_Arithmatic()
{
    int arr[5] = {10, 20, 30, 40, 50}; 
    int* ptr = arr + 2; // Point to 3rd element, 30. 
    int val; 

    std::cout<< ptr - arr <<"\n"; // we can subtract => 2

    val = *ptr++; // use pointer value in val, then increment pointer address
    print(arr);     // 10 20 30 40 50
    std::cout<<val<<" "<<ptr - arr<<"\n"; // 30 3

    ptr = arr + 2; // point to 3
    val = *++ptr; // increment pointer address, then use pointer value in val
    print(arr);  // 10 20 30 40 50 
    std::cout<<val<<" "<< ptr - arr <<"\n"; // 40 3

    ptr = arr + 2; // point to 3
    val = *ptr--; // use pointer value in val, then decrement pointer address
    print(arr);  // 10 20 30 40 50
    std::cout<< val << " " << ptr - arr <<"\n"; // 30 1

    ptr = arr + 2; // point to 3
    val = *--ptr; // decrement pointer address, then use pointer value in val
    print(arr);
    std::cout<< val <<" "<< ptr - arr <<"\n"; // 20 1

    ptr = arr + 2; // point to 3
    val = (*ptr)++; // use pointer value in val, then increment ponter Value
    print(arr); // 10 20 31 40 50
    std::cout<<val << " " << ptr - arr <<"\n"; // 30 2

    // ++ precedence > *, we can force precedence by useing () 
}

void pointers_Arithmatic2()
{
    int arr[5] = {10, 20, 30, 40, 50}; 
    int *ptr = arr; 

    while(ptr != arr + 5)   // we can compare
        std::cout<< *ptr++ <<" "; // print and move to next
}

void const_and_pointers()
{
    int val1 = 20; 
    int *ptr1 = new int; 
    *ptr1 = 10;     // can change data, it is no  constant
    ptr1 = &val1;   // can change pointer, it is not constant 

    const int* ptr2 = new int; 
    // *ptr2 = 20; // can't do that, constant data

    const int* ptr3 = & val1; 
    // *ptr3 = 20;  // can't do this. constant data
    ptr3 = ptr1;    // can change pointer, it is not constant

    int* const ptr4 = new int; 
    *ptr4 = 20; // can change data. It is not constant. 
    //ptr4 = ptr1; // can't change pointer. it is constant. 

    const int* const ptr5 = &val1; 
    // *ptr5 = 10;  // can't change data. It is constant. 
    // ptr5 = ptr1; // can't change pointer. It is constant. 

    const char* name = "hello"; // later, string class.
    delete ptr1;
    delete ptr2; 
    delete ptr4;  
}

void variable_alias1()
{
    int val = 131363; // 00000000 00000010 00000001 00100011

    std::cout<<"Size: "<< sizeof(val) <<"\n"; // 4 bytes
    std::cout<<"Value: "<< val <<"\n";    // 131363
    std::cout<<"Adress: "<< &val <<"\n"; 

    int cpy = val;
    int &ref = val;     // Both ref / val look to the SAME memory locations
    std::cout<<"ref address: "<< &ref <<"\n"; 

    val += 10; 
    std::cout<<"cpy: "<<cpy<<"\n"; 
    std::cout<<"ref: "<<ref<<"\n"; 

    ref *= 10; 
    std::cout<<"val: "<<val<<"\n"; 
}

void variable_alias2()
{
    int someVal = 10; 
    std::cout<<"Address of someVal: "<<&someVal<<"\n"; 

    // long &valRef1 = someVal; // Wrong. Same type needed

    // short &valRef2 = someVal; // Wrong aswell, different type.

    // int &someRef = 5;       // Wrong. 5 has no address

    int &a = someVal, &b = someVal, c = someVal;

    std::cout<<"Value of a: "<< a <<" ,Value of b: "<< b<<" ,Value of c: "<<c<<"\n";
    std::cout<<"Address of a: "<< &a <<" ,Address of b: "<< &b<<" ,Address of c: "<<&c<<"\n";

    // Note that the address of a and b will be the same as someVale since they are aliases of it, 
    // but the address of c is deferent since it's a new variable. 

    // & => Automatic dereference
}

// Parameter: Alias vs Pointer
void fun1(int &a) {}
void fun2(const int &a) {}
void fun3(int *a) {}

void alias_vs_pointer()
{
    int x = 10; 
    int* y = new int; 

    fun1(x); 
    // fun1(y); // can't send pointer
    // fun1(5); // can't send constant

    fun2(x); 
    // fun2(y); // can't send pointer
    fun2(5); // constant is ok

    fun3(&x); 
    fun3(y); 
    // fun3(5); // can't send constant
}

int main()
{
    //declare_initialize(); 
    //pointers_and_arrays();
    //pointers_Arithmatic(); 
    //pointers_Arithmatic2(); 
    //const_and_pointers(); // Read the function aswell.
    //variable_alias1();
    //variable_alias2();
    alias_vs_pointer(); 
}