#include <iostream>
#include <stdio.h>
#include <string>
#include <functional>

class Base
{
public:
    Base(const std::string& name) { _name = name; };
    ~Base() {};
    virtual void func1()
    {
        std::cout << "function call to func1 from object " << 
            _name << " of type Base" << std::endl;
    };
    void func2()
    {
        std::cout << "function call to func2 from object " <<
            _name << " of type Base" << std::endl;
    };
protected:
    std::string _name;
};

class Derived : public Base
{
public:
    Derived(const std::string& name) :Base(name) {};
    ~Derived() {};
    virtual void func1()
    {
        std::cout << "function call to func1 from object " <<
            _name << " of type Derived" << std::endl;
    };
    void func3()
    {
        std::cout << "function call to func3 from object " <<
            _name << " of type Derived" << std::endl;
    };
};

typedef void(Base::*pFuncA)(void);
typedef void(Derived::*pFuncB)(void);

int main()
{
    pFuncA f1 = &Base::func1;
    pFuncA f2 = &Base::func2;

    //Compile error C2440: 'initializing': 
    //cannot convert from 'void (__thiscall Derived::* )(void)' to 'pFuncA'
    //pFuncA f3 = &Derived::func1;
    //pFuncA f5 = &Derived::func3;

    pFuncA f4 = &Derived::func2;

    pFuncB f6 = &Base::func1;
    pFuncB f7 = &Base::func2;
    pFuncB f8 = &Derived::func1;
    pFuncB f9 = &Derived::func2;
    pFuncB f10 = &Derived::func3;

    Base a1("name_Base_1");
    Derived b1("name_Derived_1");

    std::invoke(f1, a1); //Base::func1 for object of type Base is invoked
    std::invoke(f1, b1); //Derived::func1 for object of type Derived is invoked
    std::invoke(f2, a1); //Base::func2 for object of type Base is invoked
    std::invoke(f2, b1); //Base::func2 for object of type Derived is invoked
    std::invoke(f4, a1); //Base::func2 for object of type Base is invoked
    std::invoke(f6, b1); //Derived::func1 for object of type Derived is invoked
    std::invoke(f7, b1); //Base::func2 for object of type Derived is invoked
    std::invoke(f8, b1); //Derived::func1 for object of type Derived is invoked
    std::invoke(f10, b1); //Derived::func3 for object of type Derived is invoked

    //std::invoke(f6, a1); //Compile error
    //std::invoke(f7, a1); //Compile error
    //std::invoke(f8, a1); //Compile error
    //std::invoke(f9, a1); //Compile error
    //std::invoke(f10, a1); //Compile error

    std::invoke(f4, b1); //Base::func2 for object of type Derived is invoked
    std::invoke(f9, b1); //Base::func2 for object of type Derived is invoked

    return 1;
}

//Output
/*
function call to func1 from object name_Base_1 of type Base
function call to func1 from object name_Derived_1 of type Derived
function call to func2 from object name_Base_1 of type Base
function call to func2 from object name_Derived_1 of type Base
function call to func2 from object name_Base_1 of type Base
function call to func1 from object name_Derived_1 of type Derived
function call to func2 from object name_Derived_1 of type Base
function call to func1 from object name_Derived_1 of type Derived
function call to func3 from object name_Derived_1 of type Derived
function call to func2 from object name_Derived_1 of type Base
function call to func2 from object name_Derived_1 of type Base
*/
