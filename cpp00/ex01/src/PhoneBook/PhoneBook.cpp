#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
	this->saved_contacts = 0;
}

Contact PhoneBook::get_contact_by_index(int index)
{
	return this->contacts[index];
}

void PhoneBook::add_contact(Contact &contact)
{
	if (this->saved_contacts == MAX_CONTACTS)
		return ;
	this->contacts[this->saved_contacts] = contact;
	this->saved_contacts++;
}

void PhoneBook::list_contacts(void)
{
	for (int i = 0; i < this->saved_contacts; i++)
	{
		std::cout << this->contacts[i].to_string() << std::endl;
		std::cout << std::endl;
	}
}

PhoneBook::~PhoneBook(){}
