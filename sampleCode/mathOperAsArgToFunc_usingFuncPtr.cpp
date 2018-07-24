#include <string>
#include <iostream>
#include <stdio.h>

typedef int(*pOperation)(const int& val1, const int& val2);

int add(const int& val1, const int& val2)
{
    return (val1 + val2);
}

int subtract(const int& val1, const int& val2)
{
    return (val1 - val2);
}

int multiply(const int& val1, const int& val2)
{
    return (val1 * val2);
}

int performMathOperation(const int& val1, const int& val2,
    const char& operationType)
{
    pOperation pFunc = nullptr;

    switch (operationType)
    {
        case '+':
        {
            pFunc = &add;
            break;
        }
        case '-':
        {
            pFunc = &subtract;
            break;
        }
        case '*':
        {
            pFunc = &multiply;
            break;
        }
        default:
        {
            std::cout << "Invalid operation!!!" << std::endl;
            break;
        }
    }

    int retVal = -1;
    if (nullptr != pFunc)
    {
        retVal = pFunc(val1, val2);
    }

    return retVal;
}

int main()
{
    int val1 = 50, val2 = 40;
    char operationType = '*';
    char wishToContinue = 'y';
    do
    {
        std::cout << "Enter the first integer: ";
        std::cin >> val1;
        std::cout << std::endl << "Enter the second integer: ";
        std::cin >> val2;
        std::cout << std::endl << "Enter one of the following operations *, -, +: ";
        std::cin >> operationType;

        int result = performMathOperation(val1, val2, operationType);
        std::cout << val1 << " " << operationType << " " << val2 << " = " << result << std::endl;

        std::cout << std::endl << "Do you wish to continue? Press y to continue: ";
        std::cin >> wishToContinue;
        std::cout << std::endl;
    } while ('y' == wishToContinue);

    return 1;
}
