#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
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

// 整数 -> 定点数
Fixed::Fixed(const int num) {
	std::cout << "Int constructor called" << std::endl;
	_value = num << _fractionalBits;
}

Fixed::Fixed(const float num) {
	std::cout << "Float constructor called" << std::endl;
	_value = roundf(num * (1 << _fractionalBits));
}

int	Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_value);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

float	Fixed::toFloat(void) const {
	return (float)_value / (1 << _fractionalBits);
}

int	Fixed::toInt(void) const {
	return (_value) >> (_fractionalBits);
}

// 运算符重载，让 Fixed 可以像 int / float 一样被 std::cout << 输出
std::ostream& operator<<(std::ostream& out, const Fixed& obj) {
	out << obj.toFloat(); // 保证精度
	return (out);
}
