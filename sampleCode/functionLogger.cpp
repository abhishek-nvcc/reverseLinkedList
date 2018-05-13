#include <iostream>
#include <string>

using namespace std;

FILE *pLogFile = nullptr;
const std::string logFileName = "F:\\docs\\git\\testCode\\sampleCode\\logFile.txt";

const char* t(const std::string& testStr)
{
    return(testStr.c_str());
}

#define LOG(fileName, functionName, lineNumber) \
{\
    if(nullptr == pLogFile)\
    {\
        fopen_s(&pLogFile , logFileName.c_str(), "w");\
    }\
    fprintf(pLogFile, "%s, %s, %d\n", t(fileName), t(functionName), \
        lineNumber);\
}

void exiting()
{
    fclose(pLogFile);
    pLogFile = nullptr;
}

class Base
{
public:
    Base()
    {
        LOG(__FILE__, __FUNCTION__, __LINE__)
    };
    ~Base() { LOG(__FILE__, __FUNCTION__, __LINE__) };
    void doSomething()
    {
        LOG(__FILE__, __FUNCTION__, __LINE__)
        func1();
        func2();
        func3();
        func4();
    };
protected:
    virtual void func1() = 0;
    virtual void func2() = 0;
    virtual void func3() = 0;
    virtual void func4() = 0;
private:
    Base(const Base&);
    Base(const Base&&);
};

class Derived1 : private Base
{
public:
    Derived1()
    {
        LOG(__FILE__, __FUNCTION__, __LINE__)
    };
    virtual ~Derived1() { LOG(__FILE__, __FUNCTION__, __LINE__) };
    void doSomethingNew()
    {
        LOG(__FILE__, __FUNCTION__, __LINE__)
        doSomething();
    };
protected:
    void func1(){ LOG(__FILE__, __FUNCTION__, __LINE__) };
    void func2(){ LOG(__FILE__, __FUNCTION__, __LINE__) };
    void func3(){ LOG(__FILE__, __FUNCTION__, __LINE__) };
    void func4(){ LOG(__FILE__, __FUNCTION__, __LINE__) };
private:
    Derived1(const Derived1&) = delete;
    Derived1 operator=(const Derived1&) = delete;
    Derived1(const Derived1&&) = delete;
    Derived1 operator=(const Derived1&&) = delete;
};

class Derived2 : private Base
{
public:
    Derived2()
    {
        LOG(__FILE__, __FUNCTION__, __LINE__)
    };
    virtual ~Derived2() { LOG(__FILE__, __FUNCTION__, __LINE__) };
    void doSomethingNew()
    {
        LOG(__FILE__, __FUNCTION__, __LINE__)
        doSomething();
    };
protected:
    void func1() { LOG(__FILE__, __FUNCTION__, __LINE__) };
    void func2() { LOG(__FILE__, __FUNCTION__, __LINE__) };
    void func3() { LOG(__FILE__, __FUNCTION__, __LINE__) };
    void func4() { LOG(__FILE__, __FUNCTION__, __LINE__) };
private:
    Derived2(const Derived2&) = delete;
    Derived2 operator=(const Derived2&) = delete;
    Derived2(const Derived2&&) = delete;
    Derived2 operator=(const Derived2&&) = delete;
};

int main()
{
    LOG(__FILE__, __FUNCTION__, __LINE__)

    Derived1 *pObjBase1 = new Derived1();
    pObjBase1->doSomethingNew();
    delete(pObjBase1);

    Derived2 *pObjBase2 = new Derived2();
    pObjBase2->doSomethingNew();
    delete(pObjBase2);
    std::string fileName, functionName, lineNumber;
    fprintf(pLogFile, "%s, %s, %s", fileName.c_str(), functionName.c_str(), lineNumber.c_str());

    std::atexit(exiting);

    return 1;
}
