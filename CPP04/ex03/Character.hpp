#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include <string>
# include <vector>

class AMateria;

class Character : public ICharacter {
	private:  
		std::string _name;
		AMateria*	_inv[4];
		std::vector<AMateria*> _floor;

		void	clarAll();

	public:  
		Character(std::string const& name);
		Character(Character const& other);
		Character& operator=(Character const& other);
		virtual ~Character();

		virtual std::string const& getName() const;

		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);
};

#endif