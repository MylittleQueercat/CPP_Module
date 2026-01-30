#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main() {
    std::srand(std::time(NULL));

    for (int i =0; i < 5; i++) {
        Base* p = generate();

        std::cout << "identify(ptr): ";
        identify(p);

        std::cout << "identify(ref): ";
        identify(*p);

        delete p;
        std::cout << "~~~~~\n";
    }
    return 0;
}