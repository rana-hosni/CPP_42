/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:27:48 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/20 09:31:03 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
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
        ~Fixed();
        Fixed(const Fixed &copy);
        Fixed &operator=(const Fixed &other);
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif