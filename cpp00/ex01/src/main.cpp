#include "Contact/Contact.hpp"
#include "PhoneBook/PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	Contact	c1 = Contact("Contact1", "c1", 637624279);
	Contact	c2 = Contact("Contact2", "c2", 637624279);
	Contact	c3 = Contact("Contact3", "c3", 637624279);
	Contact	c4 = Contact("Contact4", "c4", 637624279);
	Contact	c5 = Contact("Contact5", "c5", 637624279);
	Contact	c6 = Contact("Contact6", "c6", 637624279);
	Contact	c7 = Contact("Contact7", "c7", 637624279);
	Contact	c8 = Contact("Contact8", "c8", 637624279);
	Contact	c9 = Contact("Contact9", "c9", 637624279);

	PhoneBook	phone_book;

	phone_book.add_contact(c1);
	phone_book.add_contact(c2);
	phone_book.add_contact(c3);
	phone_book.add_contact(c4);
	phone_book.add_contact(c5);
	phone_book.add_contact(c6);
	phone_book.add_contact(c7);
	phone_book.add_contact(c8);

	phone_book.list_contacts();
	std::cout << std::endl;

	phone_book.add_contact(c9);

	phone_book.list_contacts();
}
