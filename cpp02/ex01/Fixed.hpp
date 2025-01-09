#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	private:
		int _fixedPointValue;
		static const int _fractionalBits;
	
	public:
		Fixed();
		Fixed(Fixed const & copy);
		Fixed(int const value);
		Fixed(float const value);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		Fixed & operator=(Fixed const & copy);
};

std::ostream & operator<<(std::ostream & out, Fixed const & value);

#endif