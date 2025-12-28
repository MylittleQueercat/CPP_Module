#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>
# include <iostream>

class Animal {
	protected:
		std::string type;

	public:
		Animal(void);
		Animal(const Animal& other);
		Animal& operator=(const Animal& other);
		virtual ~Animal(void);

		std::string getType(void) const;
		virtual void makeSound(void) const = 0;
};

# endif

// virtual void makeSound(void) const = 0
// 规定Animal只能当规则，不能创建实体，是抽象的概念
// 禁止 Ainimal a 和 new Animal()