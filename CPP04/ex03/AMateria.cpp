#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(std::string const& type) : _type(type) {}

AMateria::AMateria(AMateria const& other) : _type(other._type) {}

AMateria& AMateria::operator=(AMateria const& other) {
	(void)other;
	return (*this);
}

AMateria::~AMateria() {}

std::string const& AMateria::getType() const {
	return (_type);
}

void AMateria::use(ICharacter& target) {
	(void)target;
}
