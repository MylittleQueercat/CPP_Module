#include "Animal.hpp"

Animal::Animal(void) : type("Animal") {
	std::cout << "[Animal] default constructor\n";
}

Animal::Animal(const Animal& other) : type(other.type) {
	std::cout << "[Animal] copy constructor\n";
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "[Animal] copy assignment\n";
	if (this != &other)
		this->type = other.type;
	return (*this);
}

Animal::~Animal(void) {
	std::cout << "[Animal] destructor\n";
}

std::string Animal::getType(void) const {
	return (this->type);
}

// void	Animal::makeSound(void) const {
// 	std::cout << "Animal: *generic animal noises*\n";
// }