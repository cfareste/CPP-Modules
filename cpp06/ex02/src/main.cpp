#include "Base/Base.hpp"
#include "Base/A/A.hpp"
#include "Base/B/B.hpp"
#include "Base/C/C.hpp"
#include <iostream>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

static Base	*generate()
{
	Base	*base;
	int		randomNumber = static_cast<int>((rand() / static_cast<float>(RAND_MAX)) * 10);

	#ifdef DEBUG
	std::cout << "Random number: " << randomNumber << std::endl;
	#endif

	if (randomNumber >= 0 && randomNumber < 3)
		base = new A();
	else if (randomNumber >= 3 && randomNumber < 6)
		base = new B();
	else if (randomNumber >= 6 && randomNumber <= 10)
		base = new C();
	
	return base;
}

static void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown" << std::endl;
}

static void	identify(Base &p)
{
	try
	{
		dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception &e) {}

	try
	{
		dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception &e) {}

	try
	{
		dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception &e) {}

	std::cout << "Unknown" << std::endl;
}

int	main()
{
	srand(getpid() * time(NULL));

	Base	*ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;

	return 0;
}