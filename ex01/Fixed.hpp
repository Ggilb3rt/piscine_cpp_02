#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

class Fixed
{

	public:

		Fixed( void );
		Fixed( Fixed const & src );
		Fixed( int const nb );
		Fixed( float const nb );
		~Fixed( void );

		Fixed &	operator=( Fixed const & rhs );

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		int					_nb;
		static int const	_fract = 8;

};

std::ostream &	operator<<( std ::ostream & o, Fixed const & i );

#endif /* *********************************************************** FIXED_H */