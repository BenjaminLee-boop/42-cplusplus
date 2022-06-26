#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed
{
public:
    Fixed(void);
    Fixed(int val);
    Fixed(float val);
    Fixed(const Fixed &src);
    ~Fixed(void);

    Fixed &operator=(const Fixed &src);

    bool operator>(const Fixed &right) const;
    bool operator<(const Fixed &right) const;
    bool operator>=(const Fixed &right) const;
    bool operator<=(const Fixed &right) const;
    bool operator==(const Fixed &right) const;
    bool operator!=(const Fixed &right) const;

    Fixed operator+(const Fixed &right);
    Fixed operator-(const Fixed &right);
    Fixed operator*(const Fixed &right);
    Fixed operator/(const Fixed &right);

    Fixed &operator++(void);
    Fixed &operator--(void);
    Fixed operator++(int);
    Fixed operator--(int);

    float toFloat(void) const;
    int toInt(void) const;
    int getRawBits(void) const;
    void setRawBits(const int raw);

    static Fixed &min(Fixed &val1, Fixed &val2);
    static Fixed &max(Fixed &val1, Fixed &val2);
    static const Fixed &min(const Fixed &val1, const Fixed &val2);
    static const Fixed &max(const Fixed &val1, const Fixed &val2);

private:
    int _value;
    static const int _fractional = 8;
};

std::ostream &operator<<(std::ostream &os, const Fixed &src);

#endif
