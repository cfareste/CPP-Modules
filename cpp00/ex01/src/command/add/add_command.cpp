#include "add_command.hpp"
#include "Contact/Contact.hpp"
#include "Contact/contact_info/contact_info.hpp"
#include "utils/utils.hpp"
#include <iostream>

static void	get_field(std::string field_name, std::string &field)
{
	std::cout << "Enter contact's " + field_name + ": ";
	if (!std::getline(std::cin, field))
		exit(EXIT_FAILURE);
}

static void	fill_contact_information(t_contact_info &contact_info)
{
	get_field("first name", contact_info.first_name);
	get_field("last name", contact_info.last_name);
	get_field("nickname", contact_info.nickname);
	get_field("phone number", contact_info.phone_number);
	get_field("darkest secret", contact_info.darkest_secret);
}

static bool	validate_fields(t_contact_info &contact_info)
{
	if (contact_info.first_name.empty()
		|| contact_info.last_name.empty()
		|| contact_info.nickname.empty()
		|| contact_info.phone_number.empty()
		|| !is_num(contact_info.phone_number)
		|| contact_info.darkest_secret.empty())
	{
		return false;
	}
	return true;
}

static void	create_new_contact(Contact &new_contact, t_contact_info &contact_info)
{
	uint32_t	phone_number = std::stoul(contact_info.phone_number);

	new_contact = Contact(contact_info.first_name, contact_info.nickname, phone_number);
	new_contact.set_last_name(contact_info.last_name);
	new_contact.set_darkest_secret(contact_info.darkest_secret);
}

void	write_new_contact(PhoneBook &phone_book)
{
	t_contact_info	contact_info;

	fill_contact_information(contact_info);
	if (!validate_fields(contact_info))
	{
		std::cout << "Some fields are empty or invalid" << std::endl;
		return ;
	}

	Contact	new_contact;
	create_new_contact(new_contact, contact_info);

	phone_book.add_contact(new_contact);
}
