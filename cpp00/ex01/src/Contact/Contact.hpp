#pragma once

#include <string>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		uint32_t	phone_number;
		std::string	darkest_secret;

	public:
		Contact(std::string first_name, std::string nickname, uint32_t phone_number);
		Contact(const Contact &contact);

		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string	get_nickname(void);
		uint32_t	get_phone_number(void);
		std::string	get_darkest_secret(void);

		void	set_first_name(std::string first_name);
		void	set_last_name(std::string last_name);
		void	set_nickname(std::string nickname);
		void	set_phone_number(uint32_t phone_number);
		void	set_darkest_secret(std::string darkest_secret);

		std::string	to_string(void);

		Contact & operator=(const Contact &contact);

		~Contact();
};
