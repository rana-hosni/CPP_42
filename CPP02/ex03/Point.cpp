/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:02:19 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/18 16:55:06 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(): x(0), y(0){
}

Point::Point(const float a, const float b): x(a), y(b){
}

Point::Point(const Point &copy):x(copy.x), y(copy.y){
}

Point& Point::operator=(const Point &other){
    (void)other;
    return *this;
}

Point::~Point(){
}

const Fixed &Point::getX() const
{
    return x;
}

const Fixed &Point::getY() const
{
    return y;
}