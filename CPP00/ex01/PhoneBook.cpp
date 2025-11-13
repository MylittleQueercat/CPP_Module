#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	count = 0;
	next_index = 0;
}

void PhoneBook::add_contact() {
	contacts[next_index].set_contact();
	if (count < 8)
		count++;
	next_index = (next_index + 1) % 8;
}

void PhoneBook::search_contact() const{
	if (count == 0){
		std::cout << "PhoneBook is empty." << std::endl;
		return ;
	}

	std::cout << std::setw(10) << "Index" << "|"
			  << std::setw(10) << "First name" << "|"
			  << std::setw(10) << "Last name" << "|"
			  << std::setw(10) << "Nickname" << std::endl;

	for (int i = 0; i < count; i++)
		contacts[i].display_short(i);

	std::cout << "Enter the index of the contact: ";
	int	index;
	if (!(std::cin >> index)) {
		std::cout << "Invalid input." << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return ;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	if (index < 0 || index >= count) {
		std::cout << "Index out of range." << std::endl;
	}
	else {
		contacts[index].display_full();
	}
}