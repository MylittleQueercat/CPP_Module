#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	return ;
}

Fixed::Fixed(const Fixed& other) : _value(other._value) {}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other)
		this->_value = other._value;
	return (*this);
}

Fixed::~Fixed() {
	return ;
}

Fixed::Fixed(const int num) {
	_value = num << _fractionalBits;
}

Fixed::Fixed(const float num) {
	_value = roundf(num * (1 << _fractionalBits));
}

int	Fixed::getRawBits(void) const {
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

// Comparison operators
bool	Fixed::operator>(const Fixed& other) const {
	return (this->_value > other._value);
}

bool	Fixed::operator<(const Fixed& other) const {
	return (this->_value < other._value);
}

bool	Fixed::operator>=(const Fixed& other) const {
	return (this->_value >= other._value);
}

bool	Fixed::operator<=(const Fixed& other) const {
	return (this->_value <= other._value);
}

bool	Fixed::operator==(const Fixed& other) const {
	return (this->_value == other._value);
}

bool	Fixed::operator!=(const Fixed& other) const {
	return (this->_value != other._value);
}

// Arithmetic operators
Fixed	Fixed::operator+(const Fixed& other) const {
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed	Fixed::operator-(const Fixed& other) const {
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed	Fixed::operator*(const Fixed& other) const {
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed	Fixed::operator/(const Fixed& other) const {
	return (Fixed(this->toFloat() / other.toFloat()));
}

// Increment / Decrement operators
Fixed&	Fixed::operator++() {
	++this->_value;
	return (*this);
}

Fixed	Fixed::operator++(int) {
	Fixed tmp(*this);
	++this->_value;
	return (tmp);
}

Fixed&	Fixed::operator--() {
	--this->_value;
	return (*this);
}

Fixed	Fixed::operator--(int) {
	Fixed tmp(*this);
	--this->_value;
	return (tmp);
}

// Static min/max
Fixed&	Fixed::min(Fixed& a, Fixed& b) {
	return ((a < b) ? a : b);
}

Fixed&	Fixed::max(Fixed& a, Fixed& b) {
	return ((a > b) ? a : b);
}

const Fixed&	Fixed::min(const Fixed& a, const Fixed& b) {
	return ((a < b) ? a : b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b) {
	return ((a > b) ? a : b);
}