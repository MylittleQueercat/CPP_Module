#include "Zombie.hpp"

int	main()
{
	int	N = 5;
	Zombie*	horde = zombieHorde(N, "BrainEater");

	for (int i = 0; i < N; i++)
		horde[i].announce();

	delete [] horde;
	return (0);
}

// 学习数组形式的动态内存分配和内存释放