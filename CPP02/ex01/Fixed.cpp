#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->_value = other._value;
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	_value = num << _fractionalBits;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(num * (1 << _fractionalBits));
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits menber function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw) {
	_value = raw;
}

float	Fixed::toFloat(void) const {
	return (float)_value / (1 << _fractionalBits);
}

int	Fixed::toInt(void) const {
	return (_value) >> (_fractionalBits);
}

std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
	out << obj.toFloat();
	return (out);
}