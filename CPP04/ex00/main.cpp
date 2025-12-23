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
	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* wc = new WrongCat();

	std::cout << "wa type: " << wa->getType() << "\n";
	std::cout << "wc type: " << wc->getType() << "\n";

	wa->makeSound(); // WrongAnimal sound
	wc->makeSound(); // still WrongAnimal sound (NOT WrongCat)
	// 关键：因为 WrongAnimal::makeSound 不是 virtual

	delete wa;
	delete wc; // 注意：WrongAnimal 析构不是 virtual，这里严格来说会有风险
}

static void copy_tests() {
	std::cout << "\n=== Copy tests ===\n";
	Dog a;
	Dog b(a);      // copy ctor
	Dog c;
	c = b;         // assignment

	std::cout << "a type: " << a.getType() << "\n";
	std::cout << "b type: " << b.getType() << "\n";
	std::cout << "c type: " << c.getType() << "\n";

	std::cout << "\n--- Base reference dispatch ---\n";
	const Animal& ra = a;
	ra.makeSound(); // Dog sound via virtual
}

int main() {
	polymorphism_demo();
	copy_tests();
	wrong_polymorphism_demo();
	return 0;
}