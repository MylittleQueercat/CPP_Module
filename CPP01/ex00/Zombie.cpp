#include "Zombie.hpp"

//利用构造函数来进行成员初始化，把传进来的参数复制进去
Zombie::Zombie(std::string name) : name(name) {}

//析构函数，Zombie消失时自动调用
Zombie::~Zombie() {
	std::cout << name << " is destroyed ☠️" << std::endl;
}

//Zombie说话
void	Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// ~ le tilde