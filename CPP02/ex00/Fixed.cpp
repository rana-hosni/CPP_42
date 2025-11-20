/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:27:52 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/20 09:32:06 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed():_fixedPointValue(0)
{
    std::cout << GREEN << "Default constructor called" << RESET << std::endl;
}
Fixed::~Fixed()
{
    std::cout << RED << "Destructor called" << RESET << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << YELLOW << "Copy constructor called" << RESET << std::endl;
    *this = copy;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << BLUE << "Copy assignment operator called" << RESET << std::endl;
    if(this != &other)
    {
        this->_fixedPointValue = other._fixedPointValue;
    }
    return *this;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->_fixedPointValue;
}

void Fixed::setRawBits( int const raw )
{
    this->_fixedPointValue = raw;
}