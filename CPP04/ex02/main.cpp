#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

static void deep_copy_test()
{
    std::cout << "\n=== Deep copy test ===\n";
    Dog basic;
    basic.getBrain()->setIdea(0, "idea from basic");

    Dog copy(basic);
    copy.getBrain()->setIdea(0, "idea from copy");

    std::cout << "basic idea[0]: " << basic.getBrain()->getIdea(0) << "\n";
    std::cout << "copy  idea[0]: " << copy.getBrain()->getIdea(0) << "\n";

    std::cout << "\n--- Assignment test ---\n";
    Dog assign;
    assign = basic;
    assign.getBrain()->setIdea(1, "assign modified");

    std::cout << "basic  idea[1]: " << basic.getBrain()->getIdea(1) << "\n";
    std::cout << "assign idea[1]: " << assign.getBrain()->getIdea(1) << "\n";
}

int main()
{
    const int N = 4;
    Animal* animals[N];

    std::cout << "=== Creating animals array ===\n";
    for (int i = 0; i < N; i++) {
        if (i < N / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n=== Polymorphism test ===\n";
    for (int i = 0; i < N; i++)
        animals[i]->makeSound();

    deep_copy_test();

    std::cout << "\n=== Deleting animals array (as Animal*) ===\n";
    for (int i = 0; i < N; i++)
        delete animals[i];

    return 0;
}
