#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{

	public:

		Fixed( void );
		Fixed( Fixed const & src );
		Fixed( int nb );
		Fixed( float const nb );
		~Fixed( void );

		Fixed &	operator=( Fixed const & rhs );
		Fixed	operator+( Fixed const & rhs ) const;
		Fixed	operator-( Fixed const & rhs ) const;
		Fixed	operator*( Fixed const & rhs ) const;
		Fixed	operator/( Fixed const & rhs ) const;

		bool	operator>( Fixed const & rhs ) const;
		bool	operator>=( Fixed const & rhs ) const;
		bool	operator<( Fixed const & rhs ) const;
		bool	operator<=( Fixed const & rhs ) const;
		bool	operator==( Fixed const & rhs ) const;
		bool	operator!=( Fixed const & rhs ) const;
		
		Fixed &	operator++( void );
		Fixed	operator++( int );
		Fixed &	operator--( void );
		Fixed	operator--( int );


		int						getRawBits( void ) const;
		void					setRawBits( int const raw );
		float					toFloat( void ) const;
		int						toInt( void ) const;
		static Fixed &			max( Fixed & a, Fixed & b );
		const static Fixed &	max( const Fixed & a, const Fixed & b );
		static Fixed &			min( Fixed & a, Fixed & b );
		const static Fixed &	min( const Fixed & a, const Fixed & b );

	private:
		int					_nb;
		static int const	_fract = 8;

};

std::ostream &	operator<<( std ::ostream & o, Fixed const & i );

#endif /* *********************************************************** FIXED_H */