#include "Fixed.hpp"

//构造
Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

//拷贝构造
Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	this->_value = other._value;
}

//赋值
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

//析构
Fixed::~Fixed() {
	std::cout << "Destruction called" << std::endl;
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw) {
	this->_value = raw;
}