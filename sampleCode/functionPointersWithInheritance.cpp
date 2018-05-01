#include <iostream>
#include <stdio.h>
#include <string>
#include <functional>

class A
{
public:
    A(const std::string& name) { _name = name; };
    ~A() {};
    virtual void func1()
    {
        std::cout << "function call to func1 from object " << 
            _name << " of type A" << std::endl;
    };
    void func2()
    {
        std::cout << "function call to func2 from object " <<
            _name << " of type A" << std::endl;
    };
protected:
    std::string _name;
};

class B : public A
{
public:
    B(const std::string& name) :A(name) {};
    ~B() {};
    virtual void func1()
    {
        std::cout << "function call to func1 from object " <<
            _name << " of type B" << std::endl;
    };
    void func3()
    {
        std::cout << "function call to func3 from object " <<
            _name << " of type B" << std::endl;
    };
};

typedef void(A::*pFuncA)(void);
typedef void(B::*pFuncB)(void);

int main()
{
    pFuncA f1 = &A::func1;
    pFuncA f2 = &A::func2;

    //Compile error C2440: 'initializing': 
    //cannot convert from 'void (__thiscall B::* )(void)' to 'pFuncA'
    //pFuncA f3 = &B::func1;
    //pFuncA f5 = &B::func3;

    pFuncA f4 = &B::func2;

    pFuncB f6 = &A::func1;
    pFuncB f7 = &A::func2;
    pFuncB f8 = &B::func1;
    pFuncB f9 = &B::func2;
    pFuncB f10 = &B::func3;

    A a1("name_A_1");
    B b1("name_B_1");

    std::invoke(f1, a1); //A::func1 for object of type A is invoked
    std::invoke(f1, b1); //B::func1 for object of type B is invoked
    std::invoke(f2, a1); //A::func2 for object of type A is invoked
    std::invoke(f2, b1); //A::func2 for object of type B is invoked
    std::invoke(f4, a1); //A::func2 for object of type A is invoked
    std::invoke(f6, b1); //B::func1 for object of type B is invoked
    std::invoke(f7, b1); //A::func2 for object of type B is invoked
    std::invoke(f8, b1); //B::func1 for object of type B is invoked
    std::invoke(f10, b1); //B::func3 for object of type B is invoked

    //std::invoke(f6, a1); //Compile error
    //std::invoke(f7, a1); //Compile error
    //std::invoke(f8, a1); //Compile error
    //std::invoke(f9, a1); //Compile error
    //std::invoke(f10, a1); //Compile error

    std::invoke(f4, b1); //A::func2 for object of type B is invoked
    std::invoke(f9, b1); //A::func2 for object of type B is invoked

    return 1;
}

//Output
/*
function call to func1 from object name_A_1 of type A
function call to func1 from object name_B_1 of type B
function call to func2 from object name_A_1 of type A
function call to func2 from object name_B_1 of type A
function call to func2 from object name_A_1 of type A
function call to func2 from object name_B_1 of type A
function call to func1 from object name_B_1 of type B
function call to func2 from object name_B_1 of type A
function call to func1 from object name_B_1 of type B
function call to func2 from object name_B_1 of type A
function call to func3 from object name_B_1 of type B
*/
