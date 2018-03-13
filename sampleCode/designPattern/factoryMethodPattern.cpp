#include <iostream>
#include <assert.h>

class IObject
{
public:
	virtual ~IObject()
	{
		std::cout << "IObject::~IObject" << std::endl;
	};
	virtual void DoSomething() = 0;
protected:
private:
};

class CObject : public IObject
{
public:
	CObject()
	{
		std::cout << "CObject::CObject" << std::endl;
	};
	~CObject()
	{
		std::cout << "CObject::~CObject" << std::endl;
	};
	void DoSomething()
	{
		std::cout << "CObject::DoSomething" << std::endl;
	};
protected:
private:
};

class DObject : public IObject
{
public:
	DObject()
	{
		std::cout << "DObject::CObject" << std::endl;
	};
	~DObject()
	{
		std::cout << "DObject::~CObject" << std::endl;
	};
	void DoSomething()
	{
		std::cout << "DObject::DoSomething" << std::endl;
	};
protected:
private:
}; 

class EObject : public IObject
{
public:
	EObject()
	{
		std::cout << "EObject::CObject" << std::endl;
	};
	~EObject()
	{
		std::cout << "EObject::~CObject" << std::endl;
	};
	void DoSomething()
	{
		std::cout << "EObject::DoSomething" << std::endl;
	};
protected:
private:
};

class IFactory
{
public:
	virtual ~IFactory()
	{
		std::cout << "IFactory::~IFactory" << std::endl;
	};
	IObject* Create(const int typeOfObject)
	{
		std::cout << "IFactory::AnOperation" << std::endl;
		IObject *pObject = CreateObject(typeOfObject);
		return pObject;
	}
protected:
	virtual IObject* CreateObject(const int typeOfObject) = 0;
private:
};

class CFactory : public IFactory
{
public:
	CFactory()
	{
		std::cout << "CFactory::CFactory" << std::endl;
	};
	~CFactory()
	{
		std::cout << "CFactory::~CFactory" << std::endl;
	};
protected:
	IObject* CreateObject(const int typeOfObject)
	{
		std::cout << "CFactory::CreateObject" << std::endl;
		IObject* pObject = NULL;
		switch (typeOfObject)
		{
		case 0:
			pObject = new CObject();
			break;
		case 1:
			pObject = new DObject();
			break;
		case 2:
			pObject = new EObject();
			break;
		default:
			assert(0);
			break;
		}
		return(pObject);
	};
private:
};

int main()
{
	IFactory *pFactory = new CFactory();
	IObject *pObject = pFactory->Create(0);
	pObject->DoSomething();
	delete pObject;
	pObject = pFactory->Create(1);
	pObject->DoSomething();
	delete pObject;
	pObject = pFactory->Create(2);
	pObject->DoSomething();
	delete pObject;
	pObject = NULL;
	return 1;
}
