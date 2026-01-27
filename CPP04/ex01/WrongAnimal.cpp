#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "[WrongAnimal] default constructor\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type) {
	std::cout << "[WrongAnimal] copy constructor\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << "[WrongAnimal] copy assignment\n";
	if (this != &other)
		this->type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal() {
	std::cout << "[WrongAnimal] destructor\n";
}

std::string WrongAnimal::getType() const {
	return (this->type);
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal: *wrong generic noises*\n";
}