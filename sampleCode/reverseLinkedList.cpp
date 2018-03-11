#include <iostream>
#include <assert.h>
using namespace std;

int reversalCount = 1;

class A
{
    public:
    A(const int& data)
    {
        m_data = data;
        m_pHead = nullptr;
        m_pTail = nullptr;
    };
    
    int getData() const
    {
        return m_data;
    };
    
    A* getHead() const
    {
        return m_pHead;
    };
    A* getTail() const
    {
        return m_pTail;
    };
    
    void setHead(A* pHead)
    {
        m_pHead = pHead;
    };
    void setTail(A* pTail)
    {
        m_pTail = pTail;
    };
    
    void printData()
    {
        cout << m_data << endl;
        if(nullptr != m_pTail)
        {
            m_pTail->printData();
        }
    };
    
    private:
    int m_data;
    A* m_pHead;
    A* m_pTail;
};

void swapHeadAndTail(A *pElement)
{
    if(nullptr != pElement)
    {
        A* tempTail = pElement->getTail();
        A* tempHead = pElement->getHead();
        pElement->setTail(tempHead);
        pElement->setHead(tempTail);
    }
}

void reverseList(A *pOldHead, A **pNewHead)
{
    if(nullptr != pOldHead)
    {
        A *pOldTail = pOldHead->getTail();
        if(nullptr != pOldTail)
        {
            ++reversalCount;
            reverseList(pOldTail, pNewHead);
        }
        else
        {
            if(nullptr != pNewHead)
            {
                *pNewHead = pOldHead;
            }
        }
        swapHeadAndTail(pOldHead);
    }
}

int main()
{
    A a1(10);
    A a2(20);
    A a3(30);
    A a4(40);
    a1.setTail(&a2);
    a2.setHead(&a1);
    a2.setTail(&a3);
    a3.setHead(&a2);
    a3.setTail(&a4);
    a4.setHead(&a3);
    
    A *pHead = &a1;
    pHead->printData();

    A *pReversedHead = nullptr;
    reverseList(pHead, &pReversedHead);

    pReversedHead->printData();
    
    return 1;
}
