#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string const& name) : _name(name), floor(0) {
	for (int i = 0; i < 4; i++)
		_inv[i] = 0;
}

void	Character::clearAll() {
	for (int i = 0; i < 4; i++) {
		if (_inv[i]) {
			delete (_inv[i]);
			_inv[i] = 0;
		}
	}
	while (floor) {
		s_list* tmp = floor;
		floor = floor->next;
		delete tmp->content;
		delete tmp;
	}
}

Character::Character(Character const& other) : _name(other._name), floor(0) {
	for (int i = 0; i < 4; i++)
	{
		if (other._inv[i])
			_inv[i] = other._inv[i]->clone();
		else
			_inv[i] = 0;
	}
}

Character& Character::operator=(Character const& other) {
	if (this != &other) 
	{
		clearAll();
		_name = other._name;

		for (int i = 0; i < 4; i++)
		{
			if (other._inv[i])
				_inv[i] = other._inv[i]->clone();
			else
				_inv[i] = 0;
		}
	}
	return (*this);
}

Character::~Character() {
	clearAll();
}

std::string const& Character::getName() const {
	return (_name);
}

void	Character::equip(AMateria* m) {
	if (!m)
		return ;
	
	for (int i = 0; i < 4; i++)
	{
		if (_inv[i] == 0)
		{
			_inv[i] = m;
			return ;
		}
	}
	unequip_to_floor(m);
}

void	Character::unequip_to_floor(AMateria* m) {
	if (!m)
		return ;
	s_list*	newNode = new s_list;
	newNode->content = m;
	newNode->next = floor;
	floor = newNode;
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx > 3 || _inv[idx] == 0)
		return ;
	
	unequip_to_floor(_inv[idx]);
	_inv[idx] = 0;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3)
		return ;
	if (_inv[idx] == 0)
		return ;
	_inv[idx]->use(target);
}