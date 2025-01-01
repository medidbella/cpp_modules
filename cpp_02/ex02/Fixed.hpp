# ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath> 
#include <iomanip>
# include <iostream>
//f++ ++f --f f--
class Fixed{
	private:
		int value;
		static const int fractionalBitsNumber = 8;
	
	public:
		Fixed();
		Fixed(const Fixed &dest);
		Fixed(const int number);
		Fixed(const float number);
		Fixed operator =(const Fixed &otherObject);
		bool operator >(const Fixed &otherObject);
		bool operator <(const Fixed &otherObject);
		bool operator >=(const Fixed &otherObject);
		bool operator <=(const Fixed &otherObject);
		bool operator ==(const Fixed &otherObject);
		bool operator !=(const Fixed &otherObject);
		Fixed operator +(const Fixed &otherObject);
		Fixed operator -(const Fixed &otherObject);
		Fixed operator *(const Fixed &otherObject);
		Fixed operator /(const Fixed &otherObject);
		Fixed operator ++(void);
		Fixed operator ++(int);
		Fixed operator --(void);
		Fixed operator --(int);
		static Fixed& min(Fixed &number1, Fixed &number2);
		static const Fixed& min(const Fixed &number1, const Fixed &number2);
		static Fixed& max(Fixed &number1, Fixed &number2);
		static const Fixed& max(const Fixed &number1, const Fixed &number2);
		void setRawBits(int newValue);
		int	getRawBits(void) const;
		float toFloat(void) const;
		int toInt(void) const;
		int getFractionalBitsNumber() const;
		~Fixed();
};

std::ostream& operator <<(std::ostream &out, const Fixed &number);

# endif
