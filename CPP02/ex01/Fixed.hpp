/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 10:56:37 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/20 09:34:28 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;5;208m"
#define WHITE   "\033[37m"

class Fixed
{
    private:
        int _fixedPointValue;
        static const int _fractionalBits = 8;

    public:
        Fixed();
        Fixed(const int num);
        Fixed(const float num);
        Fixed(const Fixed &copy);
        Fixed &operator=(const Fixed &other);
        ~Fixed();
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat( void ) const;
        int toInt( void ) const;

};
std::ostream &operator<<(std::ostream &stream, const Fixed &fixedPoint);

#endif