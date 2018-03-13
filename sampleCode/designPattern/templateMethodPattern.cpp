#include <iostream>

class X
{
public:
	void f()
	{
		g1();
		g2();
		g3();
		g4();
	};
protected:
	virtual void g1()
	{
		std::cout << "X::g1" << std::endl;
	};
	virtual void g2()
	{
		std::cout << "X::g1" << std::endl;
	};
	virtual void g3()
	{
		std::cout << "X::g1" << std::endl;
	};
	virtual void g4()
	{
		std::cout << "X::g1" << std::endl;
	};
};

class Y : public X
{
protected:
	void g1()
	{
		std::cout << "Y::g1" << std::endl;
	};
	void g2()
	{
		std::cout << "Y::g2" << std::endl;
	};
	void g3()
	{
		std::cout << "Y::g3" << std::endl;
	};
	void g4()
	{
		std::cout << "Y::g4" << std::endl;
	};
};

int main()
{
	X *pX = new Y();
	pX->f();
	return 1;
}