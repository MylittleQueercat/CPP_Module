#include "DiamondTrap.hpp"

int main()
{
    DiamondTrap link("Link");

    std::cout << "\n"
            << BOLD YELLOW ">>> A strange echoing room deep inside a Shrine...\n"
            << RESET << std::endl;

    link.attack("a phantom Guardian");
    link.takeDamage(40);
    link.beRepaired(20);

    std::cout << "\n"
            << BOLD YELLOW ">>> The walls whisper: 'Who are you, really?'\n"
            << RESET << std::endl;

    link.whoAmI();

    std::cout << "\n"
            << BOLD YELLOW ">>> Link decides not to think too hard about multiple inheritance.\n"
            << RESET << std::endl;

    // for (int i = 0; i < 55; i++)
    //     link.beRepaired(1);

    return (0);
}