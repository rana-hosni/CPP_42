/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:15:44 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/20 10:40:08 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
Fixed a;
Fixed const b(Fixed(5.05f) * Fixed(2));

std::cout << "a is : " << a << std::endl;
std::cout << ++a << std::endl;
std::cout << "a is : " << a << std::endl;
std::cout << a++ << std::endl;
std::cout << "a is : " << a << std::endl;

std::cout << "b is : " << b << std::endl;

std::cout << "The Max is : "<< Fixed::max( a, b ) << std::endl;
std::cout << "The Min is : " << Fixed::min( a, b ) << std::endl;

std::cout << "-------------------------------------" << std::endl;

std::cout << ORANGE << "Comparison Operators :" << RESET << std::endl;
if (a > b)
    std::cout << "a is greater than b" << std::endl;
else
    std::cout << "a is not greater than b" << std::endl;
if (a < b)
    std::cout << "a is less than b" << std::endl;
else
    std::cout << "a is not less than b" << std::endl;
if (a >= b)
    std::cout << "a is greater than or equal to b" << std::endl;
else
    std::cout << "a is not greater than or equal to b" << std::endl;
if (a <= b)
    std::cout << "a is less than or equal to b" << std::endl;
else
    std::cout << "a is not less than or equal to b" << std::endl;
if (a == b)
    std::cout << "a is equal to b" << std::endl;
else
    std::cout << "a is not equal to b" << std::endl;
if (a != b)
    std::cout << "a is not equal to b" << std::endl;
else
    std::cout << "a is equal to b" << std::endl;

std::cout << "-------------------------------------" << std::endl;

std::cout << ORANGE << "Arithmetic Operators :" << RESET << std::endl;
std::cout << MAGENTA << "a + b = " << a + b << RESET<< std::endl;
std::cout << MAGENTA << "a - b = " << a - b << RESET << std::endl;
std::cout << MAGENTA << "a * b = " << a * b << RESET << std::endl;
std::cout << MAGENTA << "a / b = " << a / b << RESET << std::endl;
return 0;
}