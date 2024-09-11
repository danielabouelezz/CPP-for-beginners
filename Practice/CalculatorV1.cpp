#include <iostream> 
#include <iomanip> 

static bool isOn = true;

void setup()
{
    std::cout<<std::setw(30)<<"WELCOME TO CALCULATOR"<<"\n";
}
void operatorValidation(int& operation)
{
    while(std::cin.fail() || operation < 1 || operation > 4)
    {
        std::cin.clear();
        std::cin.ignore();
        std::cout<<"Enter a valid operation: ";
        std::cin>>operation;
    }
}

void numberValidation(double& number)
{
    bool isWrong = true;
    while(isWrong)
    {
        std::cin>>number;
        if(std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore();
            std::cout<<"Invalid input please try again: ";
        }
        else{
            std::cin.ignore();
            isWrong = false;
        }
    }
}

void otherOP()
{
    int choice{0};
    std::cout<<"Do you want to do another operation?"
    << " 1 for yes "
    << "2 for no ";
    std::cin>>choice;
    while(choice != 1 && choice != 2)
    {
        std::cout<<"Invalide choice. Enter a valid one: ";
        std::cin.clear();
        std::cin.ignore();
        std::cin>> choice;
    }
    isOn = (choice == 1);
}

void logic()
{
    double firstNumber{0}; 
    double secondNumber{0};

    std::cout<<"Please enter the first number: ";
    numberValidation(firstNumber);
    std::cout<<"Please enter the second number: ";
    numberValidation(secondNumber);

    int operation{0};
    std::cout<<"Please enter the operation: (1 for +, 2 for -, 3 for *, 4 for /)."; 
    std::cin>> operation;
    operatorValidation(operation);
    double result{0};

    switch (operation)
    {
    case 1:
        result = firstNumber + secondNumber;
        break;
    case 2: 
        result = firstNumber - secondNumber;
        break;
    case 3: 
        result = firstNumber * secondNumber;
        break;
    case 4: 
        if(secondNumber == 0)
        {
            std::cout<<"Division by zero is undefined. Please try again.\n";
            return ;
        }
        result = firstNumber / secondNumber;
        break;
    default:
        std::cout<<"Enter a valid operator"<<"\n";
        break;
    }
    std::cout<<"\n The result is : "<<result<<"\n";
    otherOP();
}

int main()
{
    while(isOn)
    {
        setup();
        logic();
    }
    return 0;
}