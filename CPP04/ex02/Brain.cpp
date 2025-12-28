#include "Brain.hpp"

Brain::Brain(void) {
	std::cout << "[Brain] default constructor\n";
}

Brain::Brain(const Brain& other) {
	std::cout << "[Brain] copy constructor\n";
	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "[Brain] copy assignment\n";
	if (this != &other) {
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}
	return (*this);
}

Brain::~Brain(void) {
	std::cout << "[Brain] destructor\n";
}