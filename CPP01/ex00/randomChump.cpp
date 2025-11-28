#include "Zombie.hpp"

void	randomChump(std::string name) {
	Zombie	zombie(name);
	zombie.announce();
}

//创建在栈stack上，无返回值，函数结束后自动销毁，自动释放
//栈像厨房的操作台，堆像仓库