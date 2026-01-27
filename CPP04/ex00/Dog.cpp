#include "Dog.hpp"

Dog::Dog() : Animal() {
	type = "Dog";
	std::cout << "[Dog] default constructor\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "[Dog] copy constructor\n";
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "[Dog] copy assignment\n";
	if (this != &other)
		Animal::operator=(other);
	return (*this);
}

Dog::~Dog() {
	std::cout << "[Dog] destructor\n";
}

void Dog::makeSound() const {
	std::cout << "Dog: Woof!\n";
}