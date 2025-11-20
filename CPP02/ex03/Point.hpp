/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:02:17 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/20 10:42:57 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define ORANGE  "\033[38;5;208m"
#define WHITE   "\033[37m"

class Point
{
    private:
        Fixed const x;
        Fixed const y;

    public:
        Point();
        Point(const float a, const float b);
        Point(const Point &copy);
        Point& operator=(const Point &other);
        ~Point();
        const Fixed &getX() const;
        const Fixed &getY() const;
};


#endif