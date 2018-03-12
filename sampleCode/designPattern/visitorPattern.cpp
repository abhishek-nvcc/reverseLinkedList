#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

class visitor
{
    public:
        visitor(){};
        virtual ~visitor(){};
        
        virtual void dumpData(const int val) = 0;
};

class squareAndDumpDataVisitor : public visitor
{
    public:
        squareAndDumpDataVisitor(){};
        virtual ~squareAndDumpDataVisitor(){};
        virtual void dumpData(const int val)
        {
            std::cout << "squaring and dumping " << val*val << std::endl;
        };
    private:
};

class doubleAndDumpDataVisitor : public visitor
{
    public:
        doubleAndDumpDataVisitor(){};
        virtual ~doubleAndDumpDataVisitor(){};
        virtual void dumpData(const int val)
        {
            std::cout << "doubling and dumping : " << val*2 << std::endl;
        };
    private:
};

class stringifyAndDumpDataVisitor : public visitor
{
    public:
        stringifyAndDumpDataVisitor(){};
        virtual ~stringifyAndDumpDataVisitor(){};
        virtual void dumpData(const int val)
        {
            std::string dataInStringForm = std::to_string(val);
            std::cout << "stringifying and dumping : " << dataInStringForm << std::endl;
        };
    private:
};

class base
{
    public:
        base(const int val){m_val = val;};
        virtual ~base(){};
        virtual void visit(visitor *pVisitor){std::cout << "data is: " << m_val << std::endl;};
    protected:
        int m_val;
};

class derived1 : public base
{
    public:
        derived1(const int val):base(val){};
        virtual ~derived1(){};
        virtual void visit(visitor *pVisitor)
        {
            base::visit(pVisitor);
            std::cout << "reducing the value of data by 1 before dumping" << std::endl;
            pVisitor->dumpData(m_val-1);
        };
};

class derived2 : public base
{
    public:
        derived2(const int val):base(val){};
        virtual ~derived2(){};
        virtual void visit(visitor *pVisitor)
        {
            base::visit(pVisitor);
            std::cout << "increasing the value of data by 5 before dumping" << std::endl;
            pVisitor->dumpData(m_val+5);
        };
};

int main()
{
    base *pObj1 = new derived1(12);
    base *pObj2 = new derived2(25);

    std::vector<base*> listOfObj = {pObj1, pObj2};
    
    visitor *pVisitor1 = new squareAndDumpDataVisitor();
    visitor *pVisitor2 = new doubleAndDumpDataVisitor();
    visitor *pVisitor3 = new stringifyAndDumpDataVisitor();
    
    for(auto pObj : listOfObj)
    {
        pObj->visit(pVisitor1);
        pObj->visit(pVisitor2);
        pObj->visit(pVisitor3);
    }
    
    return 1;
}
