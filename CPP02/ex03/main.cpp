/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:15:44 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/18 16:59:32 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int main( void ) {
    Point point(1.0f, 1.0f);
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(0.0f, 5.0f);
    
    // a = Point(0.0f, 0.0f);
    std::cout << "Triangle vertices: A" << a.getX() << "," << a.getY();
    // b = Point(5.0f, 0.0f);
    std::cout << " B" << b.getX() << "," << b.getY();
    // c = Point(0.0f, 5.0f);
    std::cout << " C" << c.getX() << "," << c.getY() << std::endl;
    // point = Point(1.0f, 1.0f);
    if (bsp(a, b, c, point))
        std::cout << "Point is inside the triangle" << std::endl;
    else
        std::cout << "Point is outside the triangle" << std::endl;
    
return 0;
}