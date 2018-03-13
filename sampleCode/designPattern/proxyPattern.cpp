/*
* @@Developer:AbhishekChaudhury
* @@DesignPattern:Proxy
*/

#include <iostream>
#include <vector>
#include <assert.h>
#include <string>
#include <algorithm>
#include <cstring>

using std::cout;
using std::endl;

//Proxy Design Pattern

class ISubject
{
public:
	virtual void Release() = 0;
	virtual void DoSomething() = 0;
};

class CRealSubject : public ISubject
{
public:
	CRealSubject()
	{
		std::cout << "CRealSubject::CRealSubject called" << std::endl;
	};
	virtual ~CRealSubject()
	{
		std::cout << "CRealSubject::~CRealSubject called" << std::endl;
	};
	virtual void Release()
	{
		std::cout << "CRealSubject::Release called" << std::endl;
		delete this;
	};
	virtual void DoSomething()
	{
		std::cout << "CRealSubject::DoSomething called" << std::endl;
	};
};

class CProxySubject : public ISubject
{
public:
	CProxySubject(ISubject* pRealSubject)
		:_pRealSubject(pRealSubject)
	{
		std::cout << "CProxySubject::CProxySubject called" << std::endl;
	};
	virtual ~CProxySubject()
	{
		std::cout << "CProxySubject::~CProxySubject called" << std::endl;
	};
	virtual void Release()
	{
		std::cout << "CProxySubject::Release called" << std::endl;
		_pRealSubject->Release();
		_pRealSubject = NULL;
		delete this;
	};
	void addRealSubject(ISubject* pSubject)
	{
		std::cout << "CProxySubject::addRealSubject called" << std::endl;
		_pRealSubject = pSubject;
	};
	virtual void DoSomething()
	{
		std::cout << "CProxySubject::DoSomething called" << std::endl;
		if (NULL != _pRealSubject)
		{
			_pRealSubject->DoSomething();
		}
	};
private:
	ISubject* _pRealSubject;
};

ISubject* GetSubject()
{
	ISubject* pSubject = NULL;

	//1. Create the real subject
	CRealSubject *pRealSubject = new CRealSubject();

	//2. Create the proxy object
	CProxySubject *pProxyObject = new CProxySubject(pRealSubject);

	//3. Return the proxy object
	pSubject = pProxyObject;

	return(pSubject);
}

int main()
{
	ISubject *pSubject = GetSubject();
	pSubject->DoSomething();

	pSubject->Release();

	return 1;
}