#include "easyfind/easyfind.hpp"
#include <set>
#include <vector>
#include <exception>

int	main()
{
	std::vector<int> vec;

	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(3);
	std::cout << "Vector size: " << vec.size() << std::endl;
	try
	{
		easyfind(vec, 1);
		easyfind(vec, 2);
		easyfind(vec, 3);
		easyfind(vec, 5);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::set<int>	set;

	set.insert(1);
	set.insert(2);
	set.insert(3);
	set.insert(2);
	std::cout << "Set size: " << set.size() << std::endl;
	try
	{
		easyfind(set, 1);
		easyfind(set, 2);
		easyfind(set, 3);
		easyfind(set, 4);
	}
	catch (const std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	return 0;
}
