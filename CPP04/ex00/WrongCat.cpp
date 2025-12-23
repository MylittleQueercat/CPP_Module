#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	this->type = "WrongCat";
	std::cout << "[WrongCat] default constructor\n";
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "[WrongCat] copy constructor\n";
	this->type = other.type;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "[WrongCat] copy assignment\n";
	if (this != &other) {
		WrongAnimal::operator=(other);
		this->type = other.type;
	}
	return (*this);
}

WrongCat::~WrongCat(void) {
	std::cout << "[WrongCat] destructor\n";
}

void WrongCat::makeSound(void) const {
	std::cout << "WrongCat: Meow?? (but it won't dispatch through WrongAnimal*)\n";
}