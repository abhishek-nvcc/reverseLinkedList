#include "logger.h"

class A
{
public:
    A()
    {
        LOGSTR("from default A constructor")
        _val = -100.0;
        _str = "from default constructor";
    };
    explicit A(const double val, const std::string& str = "default value")
    {
        LOGSTR("from default A constructor")
        _val = val;
        _str = str;
    };
    ~A()
    {
        LOGSTR("from A destructor")
    };
    A(const A& a)
    {
        LOGSTR("from A copy constructor")
        _val = a._val;
        _str = a._str;
    };
    void operator=(const A& a)
    {
        LOGSTR("from A operator=")
        _val = a._val;
        _str = a._str;
    }
    bool operator==(const A& a)
    {
        LOGSTR("from A operator=")
        bool bRet = false;
        if (a._val == _val && a._str == _str)
            bRet = true;
        return bRet;
    }
private:
    double _val;
    std::string _str;
};
class B
{
public:
    B(const A &a)
    {
        LOGSTR("from B constructor")
        _a = a;
    };
    ~B()
    {
        LOGSTR("from B destructor")
    };
private:
    A _a;
};

class C
{
public:
    C(const A &a) :_a(a)
    {
        LOGSTR("from C constructor")
    };
    ~C()
    {
        LOGSTR("from C destructor")
    };
private:
    A _a;
};

int main()
{
    A a(10.0, "obj1");
    LOGSTR("creation of A done")
    B b(a);
    LOGSTR("creation of B done")
    C c(a);
    LOGSTR("creation of C done")

    return 1;
}

//output is as follows
/*
from default A constructor
creation of A done
from default A constructor
from B constructor
from A operator=
creation of B done
from A copy constructor
from C constructor
creation of C done
from C destructor
from A destructor
from B destructor
from A destructor
from A destructor
*/
