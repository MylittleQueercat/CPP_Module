#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap link("Link");

    std::cout << "\n>>> A strange echoing room deep inside a Shrine...\n" << std::endl;

    link.attack("a phantom Guardian");
    link.takeDamage(40);
    link.beRepaired(20);

    std::cout << "\n>>> The walls whisper: 'Who are you, really?'\n" << std::endl;

    link.whoAmI();

    std::cout << "\n>>> Link decides not to think too hard about multiple inheritance.\n" << std::endl;

    return 0;
}