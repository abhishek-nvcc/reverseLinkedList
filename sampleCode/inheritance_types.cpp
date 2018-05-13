#include "logger.h"

class Base
{
public:
    Base() { LOG(__FILE__, __FUNCTION__, __LINE__) };
    virtual ~Base() { LOG(__FILE__, __FUNCTION__, __LINE__) };
    void Base_pub_1() { LOG(__FILE__, __FUNCTION__, __LINE__) };
    int base_value_pub;
protected:
    void Base_prt_1() { LOG(__FILE__, __FUNCTION__, __LINE__) };
    int base_value_prt;
private:
    void Base_prv_1() { LOG(__FILE__, __FUNCTION__, __LINE__) };
    int base_value_prv;
};

class Derived_public : public Base
{
public:
    Derived_public() { LOG(__FILE__, __FUNCTION__, __LINE__) };
    ~Derived_public() { LOG(__FILE__, __FUNCTION__, __LINE__) };
    void Derived_pub_pub_1()
    {
        LOG(__FILE__, __FUNCTION__, __LINE__)

        //Public and protected methods of base class can be called
        Base_pub_1();
        Base_prt_1();
        //Base_prv_1(); //uncomment to get compile error

        base_value_pub = 10;
        base_value_prt = 20;
        //base_value_prv = 30;
    };
protected:
    void Derived_pub_prt_1()
    {
        LOG(__FILE__, __FUNCTION__, __LINE__)

        //Public and protected methods of base class can be called
        Base_pub_1();
        Base_prt_1();
        //Base_prv_1(); //uncomment to get compile error

        base_value_pub = 10;
        base_value_prt = 20;
        //base_value_prv = 30;
    };
private:
    void Derived_pub_prv_1() { LOG(__FILE__, __FUNCTION__, __LINE__) };
};

class Derived_protected : protected Base
{
public:
    Derived_protected() { LOG(__FILE__, __FUNCTION__, __LINE__) };
    ~Derived_protected() { LOG(__FILE__, __FUNCTION__, __LINE__) };
    void Derived_prt_pub_1()
    {
        LOG(__FILE__, __FUNCTION__, __LINE__)

        //Public and protected methods of base class can be called
        Base_pub_1();
        Base_prt_1();
        //Base_prv_1(); //uncomment to get compile error

        base_value_pub = 10;
        base_value_prt = 20;
        //base_value_prv = 30;
    };
protected:
    void Derived_prt_prt_1() { LOG(__FILE__, __FUNCTION__, __LINE__) };
private:
    void Derived_prt_prv_1() { LOG(__FILE__, __FUNCTION__, __LINE__) };
};

class Derived_private : private Base
{
public:
    Derived_private() { LOG(__FILE__, __FUNCTION__, __LINE__) };
    virtual ~Derived_private() { LOG(__FILE__, __FUNCTION__, __LINE__) };
    void Derived_prv_pub_1()
    {
        LOG(__FILE__, __FUNCTION__, __LINE__)

        //Public and protected methods of base class can be called
        Base_pub_1();
        Base_prt_1();
        //Base_prv_1(); //uncomment to get compile error
    };
protected:
    void Derived_prv_prt_1() { LOG(__FILE__, __FUNCTION__, __LINE__) };
private:
    void Derived_prv_prv_1() { LOG(__FILE__, __FUNCTION__, __LINE__) };
};

class Derived_prv_level2 : public Derived_private
{
public:
    Derived_prv_level2() { LOG(__FILE__, __FUNCTION__, __LINE__) };
    ~Derived_prv_level2() { LOG(__FILE__, __FUNCTION__, __LINE__) };
protected:
    void Derived_prv_level2_prt()
    {
        LOG(__FILE__, __FUNCTION__, __LINE__)
        Derived_prv_prt_1();
        Derived_prv_prv_1();
    };
private:
};

int main()
{
    LOG(__FILE__, __FUNCTION__, __LINE__)
    Base *pObj1 = new Derived_public();
    Derived_public *pObj2 = new Derived_public();

    //Public methods of base class can be called
    pObj1->Base_pub_1();
    //Public methods of base and derived classes can be called
    pObj2->Base_pub_1();
    pObj2->Derived_pub_pub_1();

    delete pObj1;
    delete pObj2;

    //protected derivation does not give is-a-kind-of relationship
    //uncomment to get compile error, because derivation is protected
    //Base *pObj3 = new Derived_protected();
    Derived_protected *pObj3 = new Derived_protected();
    Derived_protected *pObj4 = new Derived_protected();

    //Only public methods of derived class can be called
    //pObj3->Base_pub_1(); //uncomment to get compile error
    //Public methods of only derived classes can be called
    //pObj4->Base_pub_1(); //uncomment to get compile error
    pObj4->Derived_prt_pub_1();

    delete pObj3;
    delete pObj4;

    //private derivation does not give is-a-kind-of relationship
    //uncomment to get compile error, because derivation is private
    //Base *pObj5 = new Derived_private();
    Derived_private *pObj5 = new Derived_private();
    Derived_private *pObj6 = new Derived_private();

    //Only public methods of derived class can be called
    //pObj5->Base_pub_1(); //uncomment to get compile error
    //Public methods of only derived classes can be called
    //pObj6->Base_pub_1(); //uncomment to get compile error
    pObj6->Derived_prv_pub_1();

    delete pObj5;
    delete pObj6;

    std::atexit(exiting);

    return 1;
}
