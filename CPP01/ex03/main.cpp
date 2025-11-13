#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main() {
	{
		Weapon sword("Master Sword");

		HumanA link("Link", sword);
		link.attack();
		sword.setType("Tree Branch");
		link.attack();
	}
	{
		Weapon bow("Bow");

		HumanB lynel("Lynel");
		lynel.setWeapon(bow);
		lynel.attack();
		bow.setType("Spear");
		lynel.attack();
	}
	return (0);
}

// 使用{}在函数内部来人为制造 独立作用域 scope