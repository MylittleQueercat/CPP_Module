#include "Dog.hpp"

Dog::Dog() {
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "[Dog] default constructor\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "[Dog] copy constructor\n";
	this->brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "[Dog] copy assignment\n";
	if (this != &other) {
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return (*this);
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "[Dog] destructor\n";
}

void Dog::makeSound() const {
	std::cout << "Dog: Woof!\n";
}

Brain* Dog::getBrain() const {
    return (brain);
}