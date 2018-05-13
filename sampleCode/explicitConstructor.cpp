#include "logger.h"

class A
{
    public:
        A()
        {
            LOGSTR("from default A ctor")
            _val = -100.0;
            _str = "from default ctor";
            //LOG(__FILE__, __FUNCTION__, __LINE__)
        };
        explicit A(const double val, const std::string& str = "default value")
        {
            LOGSTR("from default A ctor")
            _val = val;
            _str = str;
            //LOG(__FILE__, __FUNCTION__, __LINE__)
        };
        ~A()
        {
            LOGSTR("from A dtor")
            //LOG(__FILE__, __FUNCTION__, __LINE__)
        };
        A(const A& a)
        {
            LOGSTR("from A copy ctor")
            _val = a._val;
            _str = a._str;
            //LOG(__FILE__, __FUNCTION__, __LINE__)
        };
        void operator=(const A& a)
        {
            LOGSTR("from A operator=")
            _val = a._val;
            _str = a._str;
            //LOG(__FILE__, __FUNCTION__, __LINE__)
        }
        bool operator==(const A& a)
        {
            LOGSTR("from A operator=")
            bool bRet = false;
            if (a._val == _val && a._str == _str)
                bRet = true;
            return bRet;
            //LOG(__FILE__, __FUNCTION__, __LINE__)
        }
private:
    double _val;
    std::string _str;
};

int main()
{
    A a(10.0, "obj1");
    //uncomment to get compile error
    //will work
    //1. when explicit keyword is absent from the parameterised ctor of A, and the second parameter for the ctor is optional
    //2. when explicit keyword is absent from the parameterised ctor of A, and the second parameter for the ctor is absent
    //bool bComparison = a == 25.0;
    return 1;
}
