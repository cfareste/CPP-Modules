#include <string>
#include <iostream>

int	main()
{
	std::string	brain = "HI THIS IS BRAIN";
	std::string	*stringPTR = &brain;
	std::string	&stringREF = brain;

	std::cout << "Brain memory address: " << &brain << std::endl;
	std::cout << "Memory address held by pointer: " << stringPTR << std::endl;
	std::cout << "Brain reference memory address: " << &stringREF << "\n" << std::endl;

	std::cout << "Brain string value: " << brain << std::endl;
	std::cout << "Pointer string value: " << *stringPTR << std::endl;
	std::cout << "Reference string value: " << stringREF << std::endl;

	return 0;
}
