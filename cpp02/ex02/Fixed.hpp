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
		static Fixed & min(Fixed & a, Fixed & b);
		static Fixed & max(Fixed & a, Fixed & b);
		static const Fixed & min(Fixed const & a, Fixed const & b);
		static const Fixed & max(Fixed const & a, Fixed const & b);

		bool operator>(Fixed const & value) const;
		bool operator<(Fixed const & value) const;
		bool operator>=(Fixed const & value) const;
		bool operator<=(Fixed const & value) const;
		bool operator==(Fixed const & value) const;
		bool operator!=(Fixed const & value) const;

		Fixed operator+(Fixed const & value) const;
		Fixed operator-(Fixed const & value) const;
		Fixed operator*(Fixed const & value) const;
		Fixed operator/(Fixed const & value) const;

		Fixed & operator++(void);
		Fixed & operator--(void);
		Fixed operator++(int);
		Fixed operator--(int);
};

std::ostream & operator<<(std::ostream & out, Fixed const & value);

#endif