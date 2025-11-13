#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <limits>

class PhoneBook{
private:
	Contact contacts[8];
	int count;
	int next_index;

public:
	PhoneBook();
	void add_contact();
	void search_contact() const;
};

#endif