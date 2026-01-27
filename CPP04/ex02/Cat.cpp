#include "Cat.hpp"

Cat::Cat() {
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << "[Cat] default constructor\n";
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "[Cat] copy constructor\n";
	this->brain = new Brain(*other.brain);
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "[Cat] copy assignment\n";
	if (this != &other) {
		Animal::operator=(other);
		*brain = *other.brain;
	}
	return (*this);
}

Cat::~Cat() {
	delete this->brain;
	std::cout << "[Cat] destructor\n";
}

void	Cat::makeSound() const {
	std::cout << "Cat: Meow!\n";
}

Brain* Cat::getBrain() const {
    return (brain);
}




