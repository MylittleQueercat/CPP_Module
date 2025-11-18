#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>
# include <iostream>
# include <iomanip>

class Contact {
private:
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	std::string truncate(const std::string &str) const;
	std::string get_non_empty_input(const std::string &prompt);
	std::string get_valid_phone_number(const std::string &prompt);

public:
	void set_contact();
	void display_short(int index) const;
	void display_full() const;
};

#endif
