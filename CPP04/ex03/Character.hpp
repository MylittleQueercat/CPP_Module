#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include <string>

class AMateria;

class Character : public ICharacter {
	private:  
		std::string _name;
		AMateria*	_inv[4];
		
		struct s_list {
			AMateria* 		content;
			struct s_list*	next;
		};
		s_list*		floor;

		void	clearAll();
		void	unequip_to_floor(AMateria* m);

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