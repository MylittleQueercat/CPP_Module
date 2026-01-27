#include "Dog.hpp"

Dog::Dog() : Animal(), brain(new Brain){
	type = "Dog";
	std::cout << "[Dog] default constructor\n";
}

Dog::Dog(const Dog& other) : Animal(other), brain(new Brain(*other.brain)) {
	std::cout << "[Dog] copy constructor\n";
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
	delete brain;
	std::cout << "[Dog] destructor\n";
}

void Dog::makeSound() const {
	std::cout << "Dog: Woof!\n";
}

Brain* Dog::getBrain() const {
    return (brain);
}
