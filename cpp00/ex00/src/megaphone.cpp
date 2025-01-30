#include <string>
#include <iostream>

static void	transform_to_upper(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		str[i] = std::toupper(str[i]);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
	}

	std::string	message;
	for (int i = 1; i < argc; i++)
	{
		message = argv[i];
		transform_to_upper(message);
		std::cout << message;
	}
	std::cout << std::endl;

	return 0;
}
