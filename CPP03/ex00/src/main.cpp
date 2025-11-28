#include "ClapTrap.hpp"

int main()
{
    ClapTrap link("Link");
    ClapTrap lizalfos("Lizalfos");

    std::cout << "\n"
            << BOLD YELLOW ">>> Link sneaks into a riverside ruin.\n" 
            << RESET << std::endl;

    link.attack("Lizalfos");
    lizalfos.takeDamage(5);

    std::cout << "\n"
            << BOLD YELLOW ">>> The Lizalfos hisses suspiciously.\n" 
            << RESET << std::endl;

    lizalfos.attack("Link");
    link.beRepaired(2);

    std::cout << "\n"
            << BOLD YELLOW ">>> Link tries a flurry rush… with mixed confidence.\n" 
            << RESET << std::endl;

    link.attack("Lizalfos");
    lizalfos.takeDamage(20);

    std::cout << "\n"
            << BOLD YELLOW ">>> The Lizalfos flips dramatically into the water.\n" 
            << RESET << std::endl;
    return (0);
}

// Lizalfos 蜥蜴战士