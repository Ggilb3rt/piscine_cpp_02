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

Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
	return ;
}



int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_nb;
}

void	Fixed::setRawBits( int const raw )
{
	if (raw)
		this->_nb = raw;
	return ;
}

Fixed &	Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->_nb = rhs.getRawBits();

	return *this;
}
