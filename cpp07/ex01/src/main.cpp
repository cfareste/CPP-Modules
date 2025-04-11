#include <iostream>
#include <iter/iter.hpp>

void	increment_int(int &n)
{
	n++;
}

void	increment_char(char &n)
{
	n++;
}

template<typename T>
void	print_template(T &t)
{
	std::cout << t << std::endl;
}

int	main()
{
	int		tab[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	char	tab2[] = { 'H', 'e', 'l', 'l', 'o' };

	iter(tab, 10, print_template<const int>);
	iter(tab, 10, increment_int);
	iter(tab, 10, print_template<const int>);
	std::cout << std::endl;

	iter(tab2, 5, print_template<const char>);
	iter(tab2, 5, increment_char);
	iter(tab2, 5, print_template<const char>);

	return 0;
}
