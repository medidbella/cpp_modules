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
		void operator =(const Fixed &otherObject);
		~Fixed();
		void setRawBits(int newValue);
		int	getRawBits();
};

# endif
// Default constructor called
// Copy constructor called
// Copy assignment operator called // <-- This line may be missing depending on your implementation
// getRawBits member function called
// Default constructor called
// Copy assignment operator called
// getRawBits member function called
// getRawBits member function called
// 0
// getRawBits member function called
// 0
// getRawBits member function called
// 0
// Destructor called
// Destructor called
// Destructor called