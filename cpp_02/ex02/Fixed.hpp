# ifndef FIXED_HPP
# define FIXED_HPP

# include <cmath> 
#include <iomanip>
# include <iostream>

class Fixed{
	private:
		int value;
		static const int fractionalBitsNumber = 8;
	
	public:
		Fixed();
		Fixed(const Fixed &dest);
		Fixed(const int number);
		Fixed(const float number);
		void operator =(const Fixed &otherObject);
		void setRawBits(int newValue);
		int	getRawBits() const;
		float toFloat() const;
		int toInt(void) const;
		~Fixed();
};

std::ostream& operator <<(std::ostream &out, const Fixed &number);

# endif
