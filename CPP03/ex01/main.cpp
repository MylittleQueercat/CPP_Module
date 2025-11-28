#include "ScavTrap.hpp"

int main()
{
    ScavTrap link("Link");

    std::cout << "\n"
            << BOLD YELLOW ">>> Link enters a quiet Shrine.\n" 
            << RESET << std::endl;

    link.attack("a Guardian Scout");
    link.takeDamage(20);
    link.beRepaired(10);

    std::cout << "\n"
            << BOLD YELLOW ">>> Ancient mechanisms activate...\n" 
            << RESET << std::endl;

    link.guardGate();

    std::cout << "\n"
            << BOLD YELLOW ">>> The Shrine acknowledges Link as Gatekeeper.\n"
            << RESET << std::endl;

    return (0);
}
