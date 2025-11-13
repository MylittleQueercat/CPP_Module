#include "Zombie.hpp"

Zombie*	newZombie(std::string name) {
	Zombie* zombie = new Zombie(name);
	return (zombie);
}

//new是堆上的关键字，可用于申请内存，构造一个叫name的ZOmbie
//再返回它的地址
//delet也是关键字，用于释放内存