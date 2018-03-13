#include <iostream>

class Interface_01
{
public:
	virtual void f1() = 0;
};

class Interface_02 : public Interface_01
{
public:
	virtual void f2() = 0;
};

class Impl_01
{
public:
	void f1()
	{
		std::cout << "from Impl_01::f1" << std::endl;
	};
};

class Impl_02
{
public:
	void f1()
	{
		std::cout << "from Impl_02::f1" << std::endl;
	};
	void f2()
	{
		std::cout << "from Impl_02::f2" << std::endl;
	};
};

//This is the bridge
class Derived_01 : public Interface_01
{
public:
	Derived_01()
	{
		std::cout << "from Derived_01::Derived_01" << std::endl;
		_pImpl = new Impl_01();
	};
	void f1()
	{
		std::cout << "from Derived_01::f1" << std::endl;
		_pImpl->f1();
	};
private:
	Impl_01 *_pImpl;
};

//This is the bridge
class Derived_02 : public Interface_02
{
public:
	Derived_02()
	{
		std::cout << "from Derived_02::Derived_02" << std::endl;
		_pImpl = new Impl_02();
	}
	void f1()
	{
		std::cout << "from Derived_02::f1" << std::endl;
		_pImpl->f1();
	};
	void f2()
	{
		std::cout << "from Derived_02::f2" << std::endl;
		_pImpl->f2();
	};
private:
	Impl_02 *_pImpl;
};

int main()
{
	Interface_01 *pInterface_01 = new Derived_01();
	pInterface_01->f1();
	Interface_02 *pInterface_02 = new Derived_02();
	pInterface_02->f1();
	pInterface_02->f2();
	
	return 1;
}
