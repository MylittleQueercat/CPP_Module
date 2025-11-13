#include "Zombie.hpp"

Zombie::Zombie() {
	std::cout << "A nameless zombie appeared..." << std::endl;
}

Zombie::~Zombie() {
	std::cout << name << " was destroyed." << std::endl;
}

void	Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name) {
	this->name = name;
}