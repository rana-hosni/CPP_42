/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:15:44 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/19 09:28:38 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"


bool bsp( Point const a, Point const b, Point const c, Point const point);

void test()
{
    Point p_inside(3.0f, 3.0f);
    Point p_onV(0.0f, 0.0f);
    Point p_onEdge(5.0f, 0.0f);
    Point p_outside(8.0f, 3.0f);
    
    Point a(0.0f, 0.0f);
    Point b(10.0f, 0.0f);
    Point c(0.0f, 10.0f);

    std::cout << "Triangle vertices: A" << a.getX() << "," << a.getY();
    std::cout << " B" << b.getX() << "," << b.getY();
    std::cout << " C" << c.getX() << "," << c.getY() << std::endl;
   
    if (bsp(a, b, c, p_inside))
        std::cout << "Test Case point is inside: Point is inside the triangle" << std::endl;
    else
        std::cout << "Test Case point is inside: Point is outside the triangle" << std::endl;
    if (bsp(a, b, c, p_onV))
        std::cout << "Test Case point on vertix: Point is inside the triangle" << std::endl;
    else
        std::cout << "Test Case Point on vertix: Point is outside the triangle" << std::endl;
    if (bsp(a, b, c, p_onEdge))
        std::cout << "Test Case point on edge: Point is inside the triangle" << std::endl;
    else
        std::cout << "Test Case Point on edge: Point is outside the triangle" << std::endl;
    if (bsp(a, b, c, p_outside))
        std::cout << "Test Case point on edge: Point is inside the triangle" << std::endl;
    else
        std::cout << "Test Case Point on edge: Point is outside the triangle" << std::endl;
}


int main( void ) {
    Point point(1.0f, 1.0f);
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(0.0f, 5.0f);
    
    std::cout << "Triangle vertices: A" << a.getX() << "," << a.getY();
    std::cout << " B" << b.getX() << "," << b.getY();
    std::cout << " C" << c.getX() << "," << c.getY() << std::endl;

    if (bsp(a, b, c, point))
        std::cout << "Point is inside the triangle" << std::endl;
    else
        std::cout << "Point is outside the triangle" << std::endl;
    test();
    
    return 0;
}