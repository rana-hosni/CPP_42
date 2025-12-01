/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:33:31 by relgheit          #+#    #+#             */
/*   Updated: 2025/12/01 14:56:19 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int main()
{
    Bureaucrat bur1("John", 1);
    std::cout << bur1 << std::endl;
    std::cout << "Testing incrementGrade at top grade:" << std::endl;
    try{
        bur1.incrementGrade();
        std::cout << "After increment: " << bur1 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    Bureaucrat bur2("Alice", 150);
    std::cout << bur2 << std::endl;
    std::cout << "Testing decrementGrade at lowest grade:" << std::endl;
    try{
        bur2.decrementGrade();
        std::cout << "After decrement: " << bur2 << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;


    std::cout << "Testing GradeTooHighException:" << std::endl;
    try
    {
        Bureaucrat bur3("Bob", 0);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;

    std::cout << "Testing GradeTooLowException:" << std::endl;
    try{
        Bureaucrat bur4("Eve", 151);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "-----------------------------------" << std::endl;
    return 0;
}