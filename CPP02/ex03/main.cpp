/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 13:15:44 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/20 10:56:26 by relgheit         ###   ########.fr       */
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

    std::cout << RED << "Triangle vertices: A" << a.getX() << "," << a.getY() << RESET;
    std::cout << RED << " B" << b.getX() << "," << b.getY()<< RESET;
    std::cout << RED << " C" << c.getX() << "," << c.getY() << RESET << std::endl;
   
    if (bsp(a, b, c, p_inside))
        std::cout << GREEN << "Test Case point is inside: Point is inside the triangle" << RESET << std::endl;
    else
        std::cout << ORANGE << "Test Case point is inside: Point is outside the triangle" << RESET <<std::endl;
    if (bsp(a, b, c, p_onV))
        std::cout << GREEN << "Test Case point on vertix: Point is inside the triangle" << RESET << std::endl;
    else
        std::cout << ORANGE << "Test Case Point on vertix: Point is outside the triangle" << RESET << std::endl;
    if (bsp(a, b, c, p_onEdge))
        std::cout << GREEN << "Test Case point on edge: Point is inside the triangle" << RESET << std::endl;
    else
        std::cout << ORANGE << "Test Case Point on edge: Point is outside the triangle" << RESET << std::endl;
    if (bsp(a, b, c, p_outside))
        std::cout << GREEN << "Test Case point outside: Point is inside the triangle" << RESET << std::endl;
    else
        std::cout << ORANGE << "Test Case point outside: Point is outside the triangle" << RESET << std::endl;
    std::cout << std::endl;
    std ::cout << "-------------------------------------" << std::endl;
}
void testNeg()
{
    Point p_inside(-3.0f, -3.0f);
    Point p_onV(0.0f, 0.0f);
    Point p_onEdge(-5.0f, 0.0f);
    Point p_outside(-8.0f, -3.0f);

    Point a(0.0f, 0.0f);
    Point b(-10.0f, 0.0f);
    Point c(0.0f, -10.0f);

    std::cout << RED << "Triangle vertices: A" << a.getX() << "," << a.getY() << RESET;
    std::cout << RED << " B" << b.getX() << "," << b.getY()<< RESET;
    std::cout << RED << " C" << c.getX() << "," << c.getY() << RESET << std::endl;
   
    if (bsp(a, b, c, p_inside))
        std::cout << GREEN << "Test Case point is inside: Point is inside the triangle" << RESET << std::endl;
    else
        std::cout << ORANGE << "Test Case point is inside: Point is outside the triangle" << RESET <<std::endl;
    if (bsp(a, b, c, p_onV))
        std::cout << GREEN << "Test Case point on vertix: Point is inside the triangle" << RESET << std::endl;
    else
        std::cout << ORANGE << "Test Case Point on vertix: Point is outside the triangle" << RESET << std::endl;
    if (bsp(a, b, c, p_onEdge))
        std::cout << GREEN << "Test Case point on edge: Point is inside the triangle" << RESET << std::endl;
    else
        std::cout << ORANGE << "Test Case Point on edge: Point is outside the triangle" << RESET << std::endl;
    if (bsp(a, b, c, p_outside))
        std::cout << GREEN << "Test Case point outside: Point is inside the triangle" << RESET << std::endl;
    else
        std::cout << ORANGE << "Test Case Point outside: Point is outside the triangle" << RESET << std::endl;
    
}

int main( void ) {
    Point point(1.0f, 1.0f);
    Point a(0.0f, 0.0f);
    Point b(5.0f, 0.0f);
    Point c(0.0f, 5.0f);
    
    std::cout << RED << "Triangle vertices: A" << a.getX() << "," << a.getY() << RESET;
    std::cout << RED << " B" << b.getX() << "," << b.getY() << RESET;
    std::cout << RED << " C" << c.getX() << "," << c.getY() << RESET << std::endl;

    if (bsp(a, b, c, point))
    std::cout << GREEN << "Point is inside the triangle" << RESET << std::endl;
    else
        std::cout << ORANGE << "Point is outside the triangle" << RESET << std::endl;
    std::cout << std::endl;
    std ::cout << "-------------------------------------" << std::endl;
    test();
    testNeg();
    
    return 0;
}