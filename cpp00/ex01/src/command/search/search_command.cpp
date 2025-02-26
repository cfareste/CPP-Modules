#include "search_command.hpp"
#include "Contact/Contact.hpp"
#include "utils/utils.hpp"
#include <iostream>
#include <iomanip>

static void	print_separator()
{
	std::cout << "|";
}

static void	print_field(std::string str)
{
	if (str.length() > 10)
	{
		str.replace(9, str.length(), ".");
	}
	std::cout << std::setw(10) << str;
}

static std::string	read_index()
{
	std::string	input;

	std::cout << "Enter a contact index: ";
	if (!std::getline(std::cin, input))
		exit(EXIT_FAILURE);
	return input;
}

static int	get_contact_index()
{
	std::string input = read_index();

	if (!is_num(input))
	{
		std::cout << "The contact's index is not a number" << std::endl;
		return -1;
	}

	return std::stoi(input);
}

void	search_contacts(PhoneBook &phone_book)
{
	uint8_t	saved_contacts = phone_book.get_saved_contacts();

	if (saved_contacts == 0)
	{
		std::cout << "There are no contacts in the phone book" << std::endl;
		return ;
	}

	std::cout << "|     index|first name| last name|  nickname|" << std::endl;
	for (int i = 0; i < saved_contacts; i++)
	{
		print_separator();
		print_field(std::to_string(i));
		print_separator();
		print_field(phone_book.get_contact_by_index(i).get_first_name());
		print_separator();
		print_field(phone_book.get_contact_by_index(i).get_last_name());
		print_separator();
		print_field(phone_book.get_contact_by_index(i).get_nickname());
		print_separator();
		std::cout << std::endl;
	}

	int	index = get_contact_index();
	if (index < 0 || index + 1 > saved_contacts)
	{
		std::cout << "The contact's index is out of bounds" << std::endl;
		return ;
	}

	std::cout << phone_book.get_contact_by_index(index).to_string() << std::endl;
}
