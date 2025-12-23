#include "Cat.hpp"

Cat::Cat(void) {
	this->type = "Cat";
	std::cout << "[Cat] default constructor\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "[Cat] copy constructor\n";
	this->type = other.type;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "[Cat] copy assignment\n";
	if (this != &other) {
		Animal::operator=(other);
		this->type = other.type;
	}
	return (*this);
}

Cat::~Cat(void) {
	std::cout << "[Cat] destructor\n";
}

void	Cat::makeSound(void) const {
	std::cout << "Cat: Meow!\n";
}




