#include "Zombie.hpp"

int	main(void)
{
	Zombie*	heapZombie = newZombie("HeapZombie");
	heapZombie->announce();

	randomChump("StackZombie");

	delete (heapZombie);

	return(0);
}

// 学习stack和heap的区别，栈和堆
// 析构函数
// 指针与成员访问运算符new