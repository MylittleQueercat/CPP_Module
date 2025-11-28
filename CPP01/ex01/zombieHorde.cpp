#include "Zombie.hpp"

Zombie*	zombieHorde(int	N, std::string name) {
	if (N <= 0)
		return (NULL);
	
	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; i++) {
		std::stringstream ss;
		ss << name << "[" << i << "]";
		horde[i].setName(ss.str());
	}

	return (horde);
}

// 使用stringstream转换数字为字符串
// ss << name << "[" << i << "]"; 是把ss后面的都塞进stringstream里
// ss.str()取出组合好的字符串