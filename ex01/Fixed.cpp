#include "Fixed.hpp"

Fixed::Fixed( void ) : _nb(0)
{
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	return ;
}

Fixed::Fixed( int nb )
{
	std::cout << "Int constructor called" << std::endl;
	this->_nb = nb;
	return ;
}

Fixed::Fixed( float const nb)
{
	std::cout << "Float constructor called" << std::endl;
	(void)nb;
}

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
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
	float	ret;

	ret = (float)getRawBits();
	return (ret);
}

int		Fixed::toInt( void ) const
{
	return (getRawBits());
}


Fixed &	Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_nb = rhs.getRawBits();

	return *this;
}

std::ostream & operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();

	return o;
}