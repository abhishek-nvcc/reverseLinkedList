#include <iostream>
#include <functional>

class A
{
public:
    A(const char& name) { _mName = name; };
    ~A() {};
    void f1(const int& intVal, const char& charVal, const bool& boolVal)
    {
        std::cout << "from within A::f1" << " and A is of type " << _mName << std::endl;
        std::cout << intVal << std::endl;
        std::cout << charVal << std::endl;
        std::cout << boolVal << std::endl;
    };
    int f2(const int& intVal, const char& charVal, const bool& boolVal)
    { 
        std::cout << "from within A::f2" << " and A is of type " << _mName << std::endl;
        std::cout << intVal << std::endl;
        std::cout << charVal << std::endl;
        std::cout << boolVal << std::endl;
        return 1;
    };
    bool f3(const int& intVal, const char& charVal, const bool& boolVal)
    {
        std::cout << "from within A::f3" << " and A is of type " << _mName << std::endl;
        std::cout << intVal << std::endl;
        std::cout << charVal << std::endl;
        std::cout << boolVal << std::endl;
        return true;
    };
    bool f4(const int& intVal, const char& charVal, const bool& boolVal)
    {
        std::cout << "from within A::f4" << " and A is of type " << _mName << std::endl;
        std::cout << intVal << std::endl;
        std::cout << charVal << std::endl;
        std::cout << boolVal << std::endl;
        return true;
    };
private:
    char _mName;
};

typedef void(A::*funcPtr_f1)(const int& intVal, const char& charVal, const bool& boolVal);
typedef int(A::*funcPtr_f2)(const int& intVal, const char& charVal, const bool& boolVal);
typedef bool(A::*funcPtr_f3)(const int& intVal, const char& charVal, const bool& boolVal);

void func1(A a, funcPtr_f1 f1, const int& intVal, const char& charVal, const bool& boolVal)
{
    std::cout << "from within func1" << std::endl;
    std::invoke(f1, a, intVal, charVal, boolVal);
}

void func2(A a, funcPtr_f2 f2, const int& intVal, const char& charVal, const bool& boolVal)
{
    std::cout << "from within func2" << std::endl;
    std::invoke(f2, a, intVal, charVal, boolVal);
}

void func3(A a, funcPtr_f2 f2, funcPtr_f3 f3, const int& intVal, const char& charVal, const bool& boolVal)
{
    std::cout << "from within func3" << std::endl;
    std::invoke(f2, a, intVal, charVal, boolVal);
    std::invoke(f3, a, intVal, charVal, boolVal);
}

bool func4(const int& intVal)
{
    std::cout << "from within func4" << std::endl;
    std::cout << intVal << std::endl;
    return true;
}

bool func5(const int& intVal)
{
    std::cout << "from within func5" << std::endl;
    std::cout << intVal << std::endl;
    return false;
}

void func6(bool(*pFunc)(const int&), const int& intVal)
{
    pFunc(intVal);
}

typedef bool(*pFunc)(const int&);

void functionPointers()
{
    int intVal = 1;
    char charVal = 't';
    bool boolVal = false;
    A a('X');
    A *pA = new A('Z');

    //function pointer (to member function) declaration without using a typedef
    void (A::*pF)(const int& intVal, const char& charVal, 
        const bool& boolVal) = &A::f1;

    //function pointer (to member function) declaration using a typedef
    funcPtr_f1 pF1 = &A::f1;
    funcPtr_f2 pF2 = &A::f2;
    funcPtr_f3 pF3 = &A::f3;
    funcPtr_f3 pF4 = &A::f4;

    //calling function pointers on objects
    std::invoke(pF, a, intVal, charVal, boolVal);
    std::invoke(pF, pA, intVal, charVal, boolVal);

    //passing function pointers as function arguements
    func1(a, pF1, intVal, charVal, boolVal);
    func2(*pA, pF2, intVal, charVal, boolVal);
    func3(a, pF2, pF3, intVal, charVal, boolVal);
    func3(*pA, pF2, pF3, intVal, charVal, boolVal);

    //function pointer declaration without using a typedef
    bool(*pF5)(const int&) = &func4;
    bool(*pF6)(const int&) = &func5;
    func6(*pF5, 500);
    func6(*pF6, intVal);

    //function pointer declaration using a typedef
    pFunc pF7 = &func4;
    pFunc pF8 = &func5;
    func6(*pF7, intVal);
    func6(*pF8, 600);
}

int main()
{
    functionPointers();
    return 1;
}

//Output
/*
from within A::f1 and A is of type X
1
t
0
from within A::f1 and A is of type Z
1
t
0
from within func1
from within A::f1 and A is of type X
1
t
0
from within func2
from within A::f2 and A is of type Z
1
t
0
from within func3
from within A::f2 and A is of type X
1
t
0
from within A::f3 and A is of type X
1
t
0
from within func3
from within A::f2 and A is of type Z
1
t
0
from within A::f3 and A is of type Z
1
t
0
from within func4
500
from within func5
1
from within func4
1
from within func5
600
*/