/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:02:17 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/19 09:38:15 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"
#include <iostream>

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