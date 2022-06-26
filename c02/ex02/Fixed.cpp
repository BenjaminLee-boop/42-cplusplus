#include "Fixed.hpp"

Fixed &Fixed::min(Fixed &val1, Fixed &val2)
{
    if (val1 < val2)
        return (val1);
    else
        return (val2);
}

Fixed &Fixed::max(Fixed &val1, Fixed &val2)
{
    if (val1 > val2)
        return (val1);
    else
        return (val2);
}

const Fixed &Fixed::min(const Fixed &val1, const Fixed &val2)
{
    if (val1 < val2)
        return (val1);
    else
        return (val2);
}

const Fixed &Fixed::max(const Fixed &val1, const Fixed &val2)
{
    if (val1 > val2)
        return (val1);
    else
        return (val2);
}

int Fixed::getRawBits(void) const
{
    return (_value);
}

void Fixed::setRawBits(const int raw)
{
    _value = raw;
}

int Fixed::toInt(void) const
{
    return (_value / 256);
}

float Fixed::toFloat(void) const
{
    return ((float)_value / 256);
}

Fixed &Fixed::operator=(const Fixed &src)
{
    _value = src._value;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &src)
{
    os << src.toFloat();
    return (os);
}

bool Fixed::operator>(const Fixed &right) const
{
    return (_value > right.getRawBits());
}

bool Fixed::operator<(const Fixed &right) const
{
    return (_value < right.getRawBits());
}

bool Fixed::operator>=(const Fixed &right) const
{
    return (_value >= right.getRawBits());
}

bool Fixed::operator<=(const Fixed &right) const
{
    return (_value <= right.getRawBits());
}

bool Fixed::operator==(const Fixed &right) const
{
    return (_value == right.getRawBits());
}

bool Fixed::operator!=(const Fixed &right) const
{
    return (_value != right.getRawBits());
}

Fixed Fixed::operator+(const Fixed &right)
{
    Fixed result;

    result.setRawBits(_value + right.getRawBits());
    return (result);
}

Fixed Fixed::operator-(const Fixed &right)
{
    Fixed result;

    result.setRawBits(_value - right.getRawBits());
    return (result);
}

Fixed Fixed::operator*(const Fixed &right)
{
    Fixed result;

    result.setRawBits(_value * right.getRawBits() / 256);
    return (result);
}

Fixed Fixed::operator/(const Fixed &right)
{
    Fixed result;

    result.setRawBits(_value * 256 / right.getRawBits());
    return (result);
}

Fixed &Fixed::operator++(void)
{
    _value++;
    return (*this);
}

Fixed &Fixed::operator--(void)
{
    _value--;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed tmp;

    tmp.setRawBits(_value);
    _value++;
    return (tmp);
}

Fixed Fixed::operator--(int)
{
    Fixed tmp;

    tmp.setRawBits(_value);
    _value--;
    return (tmp);
}

Fixed::Fixed(void)
{
    _value = 0;
}

Fixed::Fixed(int val)
{
    _value = val * 256;
}

Fixed::Fixed(float val)
{
    _value = roundf(val * 256);
}

Fixed::Fixed(const Fixed &src)
{
    _value = src._value;
}

Fixed::~Fixed(void)
{
}
