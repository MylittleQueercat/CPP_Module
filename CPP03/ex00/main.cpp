#include "ClapTrap.hpp"

int main()
{
    std::cout << "==============================\n";
    std::cout << "      CLAPTRAP ARENA v0.1    \n";
    std::cout << "==============================\n\n";

    ClapTrap hero("Hero");
    ClapTrap boss("Boss");

    std::cout << "\n>>> A wild Boss appears!\n" << std::endl;

    // 第一回合：开局试探
    std::cout << "----- ROUND 1 -----" << std::endl;
    hero.attack("Boss");
    boss.takeDamage(2);

    boss.attack("Hero");
    hero.takeDamage(4);

    hero.beRepaired(3);

    // 第二回合：继续对攻
    std::cout << "\n----- ROUND 2 -----" << std::endl;
    hero.attack("Boss");
    boss.takeDamage(3);

    boss.attack("Hero");
    hero.takeDamage(5);

    // 第三回合：Hero 有点顶不住了
    std::cout << "\n----- ROUND 3 -----" << std::endl;
    hero.beRepaired(5);       // 拼命回血
    hero.attack("Boss");
    boss.takeDamage(4);

    // Boss 发疯连攻（多次调用，顺便消耗能量）
    std::cout << "\nBoss goes berserk!" << std::endl;
    for (int i = 0; i < 5; ++i)
        boss.attack("Hero");

    // 第四回合：双方都快不行了
    std::cout << "\n----- ROUND 4 -----" << std::endl;
    hero.attack("Boss");
    boss.takeDamage(10);      // 设定一个“终结一击”的伤害

    std::cout << "\n>>> Boss staggers... and collapses.\n" << std::endl;

    // 试试在 Boss 已经“没血”的状态下还想行动
    boss.attack("Hero");
    boss.beRepaired(10);

    std::cout << "\n>>> Hero wins the fight!\n" << std::endl;
    std::cout << "==============================\n";
    std::cout << "        GAME  OVER            \n";
    std::cout << "==============================\n";

    return 0;
}
