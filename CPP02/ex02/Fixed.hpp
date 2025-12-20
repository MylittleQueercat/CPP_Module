#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed {
private:  
	int					_value;
	static const int	_fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed();

	Fixed(const int num);
	Fixed(const float num);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;

	// Comparison operators
	bool operator>(const Fixed& other) const;
	bool operator<(const Fixed& other) const;
	bool operator>=(const Fixed& other) const;
	bool operator<=(const Fixed& other) const;
	bool operator==(const Fixed& other) const;
	bool operator!=(const Fixed& other) const;

	// Arithmetic operators
	Fixed operator+(const Fixed& other) const;
	Fixed operator-(const Fixed& other) const;
	Fixed operator*(const Fixed& other) const;
	Fixed operator/(const Fixed& other) const;

	// Increment / Decrement operators
	Fixed& operator++();       // 前置自增 (++a)
	Fixed operator++(int);     // 后置自增 (a++)
	Fixed& operator--();       // 前置自减 (--a)
	Fixed operator--(int);     // 后置自减 (a--)

	// Static min/max
	static Fixed& min(Fixed& a, Fixed& b);
	static const Fixed& min(const Fixed& a, const Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& out, const Fixed& obj);

#endif