#include "Cat.hpp"

Cat::Cat() : Animal() {
	type = "Cat";
	std::cout << "[Cat] default constructor\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "[Cat] copy constructor\n";
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "[Cat] copy assignment\n";
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

Cat::~Cat() {
	std::cout << "[Cat] destructor\n";
}

void	Cat::makeSound() const {
	std::cout << "Cat: Meow!\n";
}
