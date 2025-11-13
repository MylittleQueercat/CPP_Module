#include "Contact.hpp"

void	Contact::set_contact(){
	std::cout << "First name: ";
	std::getline(std::cin, first_name);

	std::cout << "Last name: ";
	std::getline(std::cin, last_name);

	std::cout << "Nickname: ";
	std::getline(std::cin, nickname);

	std::cout << "Phone number: ";
	std::getline(std::cin, phone_number);

	std::cout << "Darkest secret: ";
	std::getline(std::cin, darkest_secret);
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
	std::cout << "Nikcname: " << nickname << std::endl;
	std::cout << "Phone number" << phone_number << std::endl;
	std::cout << "Darkest secret: " << darkest_secret << std::endl;
}