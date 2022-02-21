#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed( void ) : _nb(0)
{
	return ;
}

Fixed::Fixed( Fixed const & src )
{
	*this = src;
	return ;
}

Fixed::Fixed( const int nb ) : _nb( nb << _fract )
{
	return ;
}

Fixed::Fixed( float const nb) : _nb( roundf(nb * (1 << this->_fract) ) )
{
	return ;
}

Fixed::~Fixed( void )
{
	return ;
}



int		Fixed::getRawBits( void ) const
{
	return this->_nb;
}

void	Fixed::setRawBits( int const raw )
{
	if (raw)
		this->_nb = raw;
	return ;
}



float	Fixed::toFloat( void ) const
{
	return (float)this->_nb / (1 << this->_fract);
}

int		Fixed::toInt( void ) const
{
	return (this->_nb >> _fract);
}


// Arithmetic operators
Fixed &	Fixed::operator=( Fixed const & rhs )
{
	if (this != &rhs)
		this->_nb = rhs.getRawBits();

	return *this;
}
Fixed	Fixed::operator+( Fixed const & rhs ) const
{
	return Fixed( this->toFloat() + rhs.toFloat() );
}

Fixed	Fixed::operator-( Fixed const & rhs ) const
{
	return Fixed( this->toFloat() - rhs.toFloat() );
}

Fixed	Fixed::operator*( Fixed const & rhs ) const
{
	return Fixed( this->toFloat() * rhs.toFloat() );
}

Fixed	Fixed::operator/( Fixed const & rhs ) const
{
	return Fixed( this->toFloat() / rhs.toFloat() );
}

// Comparaison operators
bool	Fixed::operator>( Fixed const & rhs ) const
{
	return (this->toFloat() > rhs.toFloat()) ? true : false;
}

bool	Fixed::operator>=( Fixed const & rhs ) const
{
	return (this->toFloat() >= rhs.toFloat()) ? true : false;
}

bool	Fixed::operator<( Fixed const & rhs ) const
{
	return (this->toFloat() < rhs.toFloat()) ? true : false;
}

bool	Fixed::operator<=( Fixed const & rhs ) const
{
	return (this->toFloat() <= rhs.toFloat()) ? true : false;
}

bool	Fixed::operator==( Fixed const & rhs ) const
{
	return (this->toFloat() == rhs.toFloat()) ? true : false;
}

bool	Fixed::operator!=( Fixed const & rhs ) const
{
	return (this->toFloat() != rhs.toFloat()) ? true : false;
}

// Increment/decrement operators
Fixed &	Fixed::operator++( void )
{
	this->_nb += 1; 
	return *this;
}

Fixed	Fixed::operator++( int )
{
	Fixed old = *this;
	operator++();
	return old;
}

Fixed &	Fixed::operator--( void )
{
	this->_nb -= 1; 
	return *this;
}

Fixed	Fixed::operator--( int )
{
	Fixed old = *this;
	operator--();
	return old;
}

// Stream operator
std::ostream & operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();

	return o;
}


Fixed &	Fixed::max( Fixed & a, Fixed & b )
{
	return (a > b) ? a : b;
}

const Fixed &	Fixed::max( const Fixed & a, const Fixed & b )
{
	return (a > b) ? a : b;
}

Fixed &	Fixed::min( Fixed & a, Fixed & b )
{
	return (a < b) ? a : b;
}

const Fixed &	Fixed::min( const Fixed & a, const Fixed & b )
{
	return (a < b) ? a : b;
}