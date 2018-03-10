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

bool checkIfChildrenSumIsSameAsData(const A& a)
{
    A *pHead = a.getHead();
    A *pTail = a.getTail();
    bool bRet = false;
    if(nullptr != pHead && nullptr != pTail)
    {
        if(a.getData() == (pHead->getData() + pTail->getData()))
        {
            bool bRetHead = checkIfChildrenSumIsSameAsData(*pHead);
            bool bRetTail = checkIfChildrenSumIsSameAsData(*pTail);
            bRet = bRetHead && bRetTail;
        }
    }
    else if(nullptr != pHead && nullptr == pTail)
    {
        if(a.getData() == pHead->getData())
        {
            bRet = checkIfChildrenSumIsSameAsData(*pHead);
        }
    }
    else if(nullptr == pHead && nullptr != pTail)
    {
        if(a.getData() == pTail->getData())
        {
            bRet = checkIfChildrenSumIsSameAsData(*pTail);
        }
    }
    else
    {
        bRet = true;
    }
    return bRet;
}

int main()
{
    A a1(2);
    A a2(2);
    A a3(3);
    A a4(5);
    A a5(8);
    A a6(10);
    A a7(4);
    A a8(1);
    a4.setHead(&a7);
    a4.setTail(&a8);
    a6.setHead(&a5);
    a6.setTail(&a1);
    a5.setHead(&a3);
    a5.setTail(&a4);
    a1.setHead(&a2);
    
    if(checkIfChildrenSumIsSameAsData(a6))
    {
        cout << "this tree was OK!!!" << endl;
    }
    else
        cout << "this tree was NOT OK!!!" << endl;

    return 1;
}
