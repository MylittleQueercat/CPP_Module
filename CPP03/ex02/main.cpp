#include "FragTrap.hpp"

int main()
{
    FragTrap link("Link");

    std::cout << "\n>>> Link wakes up on the Great Plateau… again.\n" << std::endl;

    link.attack("a Blue Bokoblin");
    link.takeDamage(30);

    std::cout << "\n>>> Link snacks on dubious food.\n" << std::endl;

    link.beRepaired(20);

    std::cout << "\n>>> Feeling oddly optimistic, Link looks around.\n" << std::endl;

    link.highFivesGuys();

    std::cout << "\n>>> No one is there, but the energy is nice.\n" << std::endl;

    return (0);
}
