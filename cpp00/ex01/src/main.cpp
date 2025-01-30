#include "Contact/Contact.hpp"
#include <iostream>

int	main(void)
{
	Contact contact_test = Contact("Pablo", "Pablin", 637624279);

	contact_test.set_last_name("Pozos");
	contact_test.set_darkest_secret("Im a nigger");
	std::cout << contact_test.to_string() << std::endl;
}
