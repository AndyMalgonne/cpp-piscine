#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base* generate()
{
	int r = rand() % 3;

	switch (r)
	{
		case 0:
			std::cout << "Generated A" << std::endl;
			return new A();
		case 1:
			std::cout << "Generated B" << std::endl;
			return new B();
		case 2:
			std::cout << "Generated C" << std::endl;
			return new C();
		default:
			return 0;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Error" << std::endl;
}

void identify(Base & p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (...) {}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (...) {}

	std::cout << "Error" << std::endl;
}

int main()
{
	srand(time(0));

	Base* b1 = generate();
	Base* b2 = generate();
	Base* b3 = generate();
	Base* b4 = generate();
	Base* b5 = generate();



	std::cout << "Identify b1" << std::endl;
	identify(b1);
	identify(*b1);

	std::cout << "Identify b2" << std::endl;
	identify(b2);
	identify(*b2);

	std::cout << "Identify b3" << std::endl;
	identify(b3);
	identify(*b3);

	std::cout << "Identify b4" << std::endl;
	identify(b4);
	identify(*b4);

	std::cout << "Identify b5" << std::endl;
	identify(b5);
	identify(*b5);


	delete b1;
	delete b2;
	delete b3;
	delete b4;
	delete b5;

	return 0;
}