#include "Dog.hpp"

Dog::Dog(void) {
	this->type = "Dog";
	std::cout << "[Dog] default constructor\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "[Dog] copy constructor\n";
	this->type = other.type;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "[Dog] copy assignment\n";
	if (this != &other) {
		Animal::operator=(other);
		this->type = other.type;
	}
	return (*this);
}

Dog::~Dog(void) {
	std::cout << "[Dog] destructor\n";
}

void Dog::makeSound(void) const {
	std::cout << "Dog: Woof!\n";
}