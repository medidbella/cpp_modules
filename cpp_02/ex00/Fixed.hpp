# ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed{
	private:
		int value;
		static const int fractionalBitsNumber;

	public:
		Fixed();
		Fixed(const Fixed &dest);
		Fixed operator =(const Fixed &otherObject);
		~Fixed();
		void setRawBits(int newValue);
		int	getRawBits();
};

# endif
