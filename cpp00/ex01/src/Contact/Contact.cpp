#include "Contact.hpp"

Contact::Contact()
{
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_number = 0;
	this->darkest_secret = "";
}

Contact::Contact(std::string first_name, std::string nickname, uint32_t phone_number)
{
	this->first_name = first_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
}

Contact::Contact(const Contact &contact)
{
	this->first_name = contact.first_name;
	this->last_name = contact.last_name;
	this->nickname = contact.nickname;
	this->phone_number = contact.phone_number;
	this->darkest_secret = contact.darkest_secret;
}

std::string	Contact::get_first_name(void)
{
	return this->first_name;
}

std::string	Contact::get_last_name(void)
{
	return this->last_name;
}

std::string	Contact::get_nickname(void)
{
	return this->nickname;
}

uint32_t	Contact::get_phone_number(void)
{
	return this->phone_number;
}

std::string	Contact::get_darkest_secret(void)
{
	return this->darkest_secret;
}

void	Contact::set_first_name(std::string first_name)
{
	this->first_name = first_name;
}

void	Contact::set_last_name(std::string last_name)
{
	this->last_name = last_name;
}

void	Contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

void	Contact::set_phone_number(uint32_t phone_number)
{
	this->phone_number = phone_number;
}

void	Contact::set_darkest_secret(std::string darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

std::string	Contact::to_string(void)
{
	std::string	stringified_contact = "";

	stringified_contact += "First name: " + this->first_name + "\n";
	stringified_contact += "Last name: " + this->last_name + "\n";
	stringified_contact += "Nickname: " + this->nickname + "\n";
	stringified_contact += "Phone number: " + std::to_string(this->phone_number) + "\n";
	stringified_contact += "Darkest secret: " + this->darkest_secret;
	return stringified_contact;
}

Contact	&Contact::operator=(const Contact &contact)
{
	if (this == &contact)
		return *this;
	this->first_name = contact.first_name;
	this->last_name = contact.last_name;
	this->nickname = contact.nickname;
	this->phone_number = contact.phone_number;
	this->darkest_secret = contact.darkest_secret;
	return *this;
}

Contact::~Contact(){}
