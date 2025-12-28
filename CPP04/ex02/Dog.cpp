#include "Dog.hpp"

Dog::Dog(void) {
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "[Dog] default constructor\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "[Dog] copy constructor\n";
	this->brain = new Brain(*other.brain);
}

// this->brain = other.brain; ❌ 这是浅拷贝（会炸）
// new Brain(*other.brain);   ✅ 拷贝“内容”

Dog& Dog::operator=(const Dog& other) {
	std::cout << "[Dog] copy assignment\n";
	if (this != &other) {
		Animal::operator=(other);
		delete this->brain;
		this->brain = new Brain(*other.brain);
	}
	return (*this);
}

Dog::~Dog(void) {
	delete this->brain;
	std::cout << "[Dog] destructor\n";
}

void Dog::makeSound(void) const {
	std::cout << "Dog: Woof!\n";
}