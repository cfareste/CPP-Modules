#include "search_command.hpp"
#include "Contact/Contact.hpp"
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
}
