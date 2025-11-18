/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 15:36:09 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/18 16:45:58 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include "Fixed.hpp"

Fixed cross(Point const p, Point const a, Point const b)
{
    Fixed Vx1 = b.getX() - a.getX();
    Fixed Vy1 = b.getY() - a.getY();
    Fixed Vx2 = p.getX() - a.getX();
    Fixed Vy2 = p.getY() - a.getY();
    return (Vx1 * Vy2 - Vy1 * Vx2);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    Fixed d1, d2, d3;
    bool all_neg, all_pos;

    d1 = cross(point, a, b);
    std::cout << "d1: " << d1 << std::endl;
    d2 = cross(point, b, c);
    std::cout << "d2: " << d2 << std::endl;
    d3 = cross(point, c, a);
    std::cout << "d3: " << d3 << std::endl;

    all_neg = (d1 < 0) && (d2 < 0) && (d3 < 0);
    std::cout << "all_neg: " << all_neg << std::endl;
    all_pos = (d1 > 0) && (d2 > 0) && (d3 > 0);
    std::cout << "all_pos: " << all_pos << std::endl;

    return (all_neg || all_pos);
}