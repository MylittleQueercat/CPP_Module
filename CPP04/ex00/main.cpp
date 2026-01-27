#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

static void polymorphism_demo() {
	std::cout << "\n=== Polymorphism demo (Animal*) ===\n";
	const Animal* meta = new Animal();
	const Animal* D = new Dog();
	const Animal* C = new Cat();

	std::cout << "D type: " << D->getType() << "\n";
	std::cout << "C type: " << C->getType() << "\n";

	C->makeSound();   // Cat sound
	D->makeSound();   // Dog sound
	meta->makeSound(); // Animal sound

	delete meta;
	delete D;
	delete C;
}

static void wrong_polymorphism_demo() {
    std::cout << "\n=== Wrong polymorphism demo (WrongAnimal*) ===\n";
    WrongAnimal wa;
    WrongCat wc;

    const WrongAnimal* pwa = &wa;
    const WrongAnimal* pwc = &wc;

    pwa->makeSound();
    pwc->makeSound();
}

static void copy_tests() {
	std::cout << "\n=== Copy tests ===\n";
	Dog a;
	Dog b(a);     
	Dog c;
	c = b; 

	std::cout << "a type: " << a.getType() << "\n";
	std::cout << "b type: " << b.getType() << "\n";
	std::cout << "c type: " << c.getType() << "\n";

	std::cout << "\n--- Base reference dispatch ---\n";
	const Animal& ra = a;
	ra.makeSound();
}

int main() {
	polymorphism_demo();
	copy_tests();
	wrong_polymorphism_demo();
	return 0;
}