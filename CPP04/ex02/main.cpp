#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

// Animal a; // should not compile (abstract class)

 int main() {
	const int N = 4;
	Animal* animals[N];

	for (int i = 0; i < N; i++) {
		if (i < N / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n--- deleting animals ---\n";
	for (int i = 0; i < N; i++)
		delete animals[i];

	return 0;
}