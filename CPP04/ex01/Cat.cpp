#include "Cat.hpp"

Cat::Cat(void) {
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
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}

Cat::~Cat(void) {
	delete this->brain;
	std::cout << "[Cat] destructor\n";
}

void	Cat::makeSound(void) const {
	std::cout << "Cat: Meow!\n";
}




