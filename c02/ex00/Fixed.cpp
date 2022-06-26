#include "Fixed.hpp"

int Fixed::getRawBits(void)
{
    std::cout << "getRawBits member function called" << std::endl;
    return (_value);
}

void Fixed::setRawBits(const int raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    _value = raw;
}

Fixed &Fixed::operator=(const Fixed &src)
{
    std::cout << "Assignment operator called" << std::endl;
    _value = src._value;
    return *this;
}

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    _value = 0;
}

Fixed::Fixed(const Fixed &src)
{
    std::cout << "Copy constructor called" << std::endl;
    _value = src._value;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}
