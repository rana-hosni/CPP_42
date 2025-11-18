/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:27:52 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/18 15:34:08 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_fixedPointValue(0)
{
    // std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed()
{
    // std::cout << "Destructor called" << std::endl;
}
Fixed::Fixed(const int num):_fixedPointValue(num << _fractionalBits)
{
    // std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float num):_fixedPointValue(roundf(num * (1 << _fractionalBits)))
{
    // std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    // std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    // std::cout << "Copy assignment operator called" << std::endl;
    if(this != &other)
    {
        this->_fixedPointValue = other._fixedPointValue;
    }
    return *this;
}

int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits( int const raw )
{
    this->_fixedPointValue = raw;
}

float Fixed::toFloat( void ) const
{
    return static_cast<float>(this->_fixedPointValue) / static_cast<float>(1 << _fractionalBits);
}

int Fixed::toInt( void ) const
{
    return this->_fixedPointValue >> _fractionalBits;
}

bool Fixed::operator>(const Fixed &other) const
{
    return this->_fixedPointValue > other._fixedPointValue;
}

bool Fixed::operator<(const Fixed &other) const
{
    return this->_fixedPointValue < other._fixedPointValue;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return this->_fixedPointValue >= other._fixedPointValue;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return this->_fixedPointValue <= other._fixedPointValue;
}

bool Fixed::operator==(const Fixed &other) const
{
    return this->_fixedPointValue == other._fixedPointValue;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return this->_fixedPointValue != other._fixedPointValue;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed &other) const
{
    if (other._fixedPointValue == 0)
    {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed(0);
    }
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
    this->_fixedPointValue++;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this;
    this->_fixedPointValue++;
    return temp;
}

Fixed &Fixed::operator--()
{
    this->_fixedPointValue--;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this;
    this->_fixedPointValue--;
    return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    return b;
}


std::ostream &operator<<(std::ostream &stream, const Fixed &fixedPoint)
{
    stream << fixedPoint.toFloat();
    return stream;
}