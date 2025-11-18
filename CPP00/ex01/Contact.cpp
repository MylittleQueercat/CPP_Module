#include "Contact.hpp"

std::string Contact::get_non_empty_input(const std::string &prompt)
{
    std::string input;

    do {
        std::cout << prompt;
        std::getline(std::cin, input);
        if (!std::cin)  // 如果遇到 EOF
            return ("");  // 或者你想 return input;
    } while (input.empty());

    return (input);
}

std::string Contact::get_valid_phone_number(const std::string &prompt)
{
	std::string number;

	while (true)
	{
		std::cout << prompt;
		std::getline(std::cin, number);

		if (!std::cin)
			return ("");

		if (number.empty())
			continue ;
		
		bool all_digits = true;
		for (size_t i = 0; i < number.length(); i++)
		{
			if (!std::isdigit(number[i]))
			{
				all_digits = false;
				break ;
			}
		}
		if (!all_digits)
		{
			std::cout << "Phone number must contain digits only." << std::endl;
			continue ;
		}

		if (number.length() < 3 || number.length() > 15)
		{
			std::cout << "Phone number must be between 3 and 15 digits." << std::endl;
			continue ;
		}

		return (number);
	}
}

void Contact::set_contact() {
	first_name     = get_non_empty_input("First name: ");
	last_name      = get_non_empty_input("Last name: ");
	nickname       = get_non_empty_input("Nickname: ");
	phone_number   = get_valid_phone_number("Phone number: ");
	darkest_secret = get_non_empty_input("Darkest secret: ");
}

std::string Contact::truncate(const std::string &str) const{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	return (str);
}
// 如果字符串长度大于10，就截取前9个字符再加一个点 "."

void Contact::display_short(int index) const{
	std::cout << "|" << std::setw(10) << index
			  << "|" << std::setw(10) << truncate(first_name)
			  << "|" << std::setw(10) << truncate(last_name)
			  << "|" << std::setw(10) << truncate(nickname)
			  << "|" << std::endl;
}
// setw 用于对齐输出

void Contact::display_full() const {
	std::cout << "First name: " << first_name << std::endl;
	std::cout << "Last name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone number: " << phone_number << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
}