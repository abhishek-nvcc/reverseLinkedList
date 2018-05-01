#include <iostream>
#include <stdio.h>
#include <string>
#include <functional>

/*
Base class does not know about the functions in derived class
So, function pointers to Base class member methods cannot point to Derived class member methods
*/

/*
Irrespective of the type of function pointer, the method corresponding to the object type gets called
*/

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
            _name << " which is of type Derived" << std::endl;
    };
    void func3()
    {
        std::cout << "function call to func3 from object " <<
            _name << " which is of type Derived" << std::endl;
    };
};

typedef void(Base::*pFuncBase)(void);
typedef void(Derived::*pFuncDerived)(void);

int main()
{
    Base a1("name_Base_1");
    Derived b1("name_Derived_1");

    pFuncBase f1 = &Base::func1;
    pFuncDerived f16 = reinterpret_cast<pFuncDerived>(f1);
    printf("%p\n", f1);
    printf("%p\n", f16);
    std::invoke(f1, a1);
    std::invoke(f1, b1);
    std::invoke(f16, b1);

    pFuncDerived f6 = f1;
    pFuncBase f11 = reinterpret_cast<pFuncBase>(f6);
    printf("%p\n", f6);
    printf("%p\n", f11);
    std::invoke(f6, b1);
    std::invoke(f11, a1);
    std::invoke(f11, b1);

    pFuncBase f2 = &Base::func2;
    pFuncDerived f17 = reinterpret_cast<pFuncDerived>(f2);
    printf("%p\n", f2);
    printf("%p\n", f17);
    std::invoke(f2, a1);
    std::invoke(f2, b1);
    std::invoke(f17, b1);

    pFuncDerived f7 = f2;
    pFuncBase f12 = reinterpret_cast<pFuncBase>(f7);
    printf("%p\n", f7);
    printf("%p\n", f12);
    std::invoke(f7, b1);
    std::invoke(f12, a1);
    std::invoke(f12, b1);

    pFuncBase f4 = &Derived::func2;
    pFuncDerived f18 = reinterpret_cast<pFuncDerived>(f4);
    printf("%p\n", f4);
    printf("%p\n", f18);
    std::invoke(f4, a1);
    std::invoke(f4, b1);
    std::invoke(f18, b1);

    pFuncDerived f9 = f4;
    pFuncBase f14 = reinterpret_cast<pFuncBase>(f9);
    printf("%p\n", f9);
    printf("%p\n", f14);
    std::invoke(f9, b1);
    std::invoke(f14, a1);
    std::invoke(f14, b1);

    //Compile error C2440: 'initializing': 
    //cannot convert from 'void (__thiscall Derived::* )(void)' to 'pFuncBase'
    //pFuncBase f3 = &Derived::func1;
    //pFuncBase f5 = &Derived::func3;

    pFuncDerived f8 = &Derived::func1;
    pFuncBase f13 = reinterpret_cast<pFuncBase>(f8);
    printf("%p\n", f8);
    printf("%p\n", f13);
    std::invoke(f8, b1);
    std::invoke(f13, a1);
    std::invoke(f13, b1);

    pFuncDerived f10 = &Derived::func3;
    pFuncBase f15 = reinterpret_cast<pFuncBase>(f10);
    printf("%p\n", f10);
    printf("%p\n", f15);
    std::invoke(f10, b1);
    std::invoke(f15, a1);
    std::invoke(f15, b1);

    //std::invoke(f6, a1); //Compile error
    //std::invoke(f7, a1); //Compile error
    //std::invoke(f8, a1); //Compile error
    //std::invoke(f9, a1); //Compile error
    //std::invoke(f10, a1); //Compile error
    //std::invoke(f16, a1); //Compile error
    //std::invoke(f17, a1); //Compile error
    //std::invoke(f18, a1); //Compile error
    //std::invoke(f10, a1); //Compile error

    return 1;
}

//Output
/*
00091393
00091393
function call to func1 from object name_Base_1 of type Base
function call to func1 from object name_Derived_1 which is of type Derived
function call to func1 from object name_Derived_1 which is of type Derived
00091393
00091393
function call to func1 from object name_Derived_1 which is of type Derived
function call to func1 from object name_Base_1 of type Base
function call to func1 from object name_Derived_1 which is of type Derived
00091492
00091492
function call to func2 from object name_Base_1 of type Base
function call to func2 from object name_Derived_1 of type Base
function call to func2 from object name_Derived_1 of type Base
00091492
00091492
function call to func2 from object name_Derived_1 of type Base
function call to func2 from object name_Base_1 of type Base
function call to func2 from object name_Derived_1 of type Base
00091492
00091492
function call to func2 from object name_Base_1 of type Base
function call to func2 from object name_Derived_1 of type Base
function call to func2 from object name_Derived_1 of type Base
00091492
00091492
function call to func2 from object name_Derived_1 of type Base
function call to func2 from object name_Base_1 of type Base
function call to func2 from object name_Derived_1 of type Base
00091393
00091393
function call to func1 from object name_Derived_1 which is of type Derived
function call to func1 from object name_Base_1 of type Base
function call to func1 from object name_Derived_1 which is of type Derived
0009114A
0009114A
function call to func3 from object name_Derived_1 which is of type Derived
function call to func3 from object name_Base_1 which is of type Derived
function call to func3 from object name_Derived_1 which is of type Derived
*/
