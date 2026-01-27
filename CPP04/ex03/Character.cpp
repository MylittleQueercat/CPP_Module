#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(std::string const& name) : _name(name) {
	for (int i = 0; i < 4; i++)
		_inv[i] = 0;
}

void	Character::clearAll() {
	for (int i = 0; i < 4; i++)
	{
		delete (_inv[i]);
		_inv[i] = 0;
	}
	for (size_t i = 0; i < _floor.size(); i++)
		delete (_floor[i]);
	_floor.clear();
}

Character::Character(Character const& other) : _name(other._name) {
	for (int i = 0; i < 4; i++)
		_inv[i] = 0;
	
	for (int i = 0; i < 4; i++)
	{
		if (other._inv[i])
			_inv[i] = other._inv[i]->clone();
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
	_floor.push_back(m);
}

void	Character::unequip(int idx) {
	if (idx < 0 || idx > 3)
		return ;
	if (_inv[idx] == 0)
		return ;
	
	_floor.push_back(_inv[idx]);
	_inv[idx] = 0;
}

void	Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx > 3)
		return ;
	if (_inv[idx] == 0)
		return ;
	_inv[idx]->use(target);
}