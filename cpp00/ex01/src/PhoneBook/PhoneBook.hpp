#pragma once

#define MAX_CONTACTS 8

#include "Contact/Contact.hpp"

class PhoneBook
{
	private:
		uint8_t	saved_contacts;
		Contact	contacts[MAX_CONTACTS];

		void	shift_contacts();
		void	replace_oldest_contact(Contact &contact);

	public:
		PhoneBook();

		Contact	get_contact_by_index(int index);

		void	add_contact(Contact &contact);

		void	list_contacts(void);

		~PhoneBook();
};
