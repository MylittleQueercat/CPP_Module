#include "FragTrap.hpp"

int main()
{
    FragTrap link("Link");

    std::cout << "\n"
            <<  BOLD YELLOW ">>> Link wakes up on the Great Plateau… again.\n" 
            <<  RESET << std::endl;

    link.attack("a Blue Bokoblin");
    link.takeDamage(30);

    std::cout << "\n"
            <<  BOLD YELLOW ">>> Link snacks on dubious food.\n" 
            <<  RESET << std::endl;

    link.beRepaired(20);

    std::cout << "\n"
            <<  BOLD YELLOW ">>> Feeling oddly optimistic, Link looks around.\n" 
            <<  RESET << std::endl;

    link.highFivesGuys();

    std::cout << "\n"
            << BOLD YELLOW ">>> No one is there, but the energy is nice.\n" 
            << RESET << std::endl;

    return (0);
}
