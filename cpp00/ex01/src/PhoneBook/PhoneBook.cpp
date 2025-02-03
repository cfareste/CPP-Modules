#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
	this->saved_contacts = 0;
}

void	PhoneBook::shift_contacts()
{
	int	new_pos = 0;
	int	old_pos = 1;

	while (old_pos < MAX_CONTACTS)
	{
		this->contacts[new_pos] = this->contacts[old_pos];
		new_pos++;
		old_pos++;
	}
}

void	PhoneBook::replace_oldest_contact(Contact &contact){
	this->shift_contacts();
	this->contacts[MAX_CONTACTS - 1] = contact;
}

Contact	PhoneBook::get_contact_by_index(int index)
{
	return this->contacts[index];
}

void	PhoneBook::add_contact(Contact &contact)
{
	if (this->saved_contacts == MAX_CONTACTS)
	{
		this->replace_oldest_contact(contact);
		return ;
	}
	this->contacts[this->saved_contacts] = contact;
	this->saved_contacts++;
}

void	PhoneBook::list_contacts(void)
{
	for (int i = 0; i < this->saved_contacts; i++)
	{
		std::cout << this->contacts[i].to_string() << std::endl;
		std::cout << std::endl;
	}
}

PhoneBook::~PhoneBook(){}
