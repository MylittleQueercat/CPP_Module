#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
private:
	std::string	name;

public:
	Zombie(std::string name);
	~Zombie();

	void	announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif

// ~Zombie()是析构函数，当对象生命周期结束或你 delete它时会自动调用
