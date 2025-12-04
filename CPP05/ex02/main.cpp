/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:33:31 by relgheit          #+#    #+#             */
/*   Updated: 2025/12/04 15:07:12 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void testShrubberyCreationForm(Bureaucrat& bur1){
    try{
        AForm* form1 = new ShrubberyCreationForm("Home");
        try{
            form1->beSigned(bur1);
            std::cout << *form1;
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        try {
            bur1.executeForm(*form1);
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        delete form1;
    }
    catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }
}

void testRobotomyRequestForm(Bureaucrat& bur1){
    try{
        AForm* form2 = new RobotomyRequestForm("Robot");
        try {
            form2->beSigned(bur1);
            std::cout << *form2;
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        try{
            bur1.executeForm(*form2);
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        delete form2;
    }
    catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }
}

void testPresidentialPardonForm(Bureaucrat& bur1){
    try{
        AForm* form3 = new PresidentialPardonForm("Alice");
        try{
            form3->beSigned(bur1);
            std::cout << *form3;
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        try {
            bur1.executeForm(*form3);
        }
        catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
        }
        delete form3;
    }
    catch(const std::exception& e){
        std::cout << e.what() << std::endl;
    }
}

int main()
{
    Bureaucrat bur1("FailJohn", 150);
    Bureaucrat bur2("Jane", 50);
    Bureaucrat bur3("Boss", 1);
    std::cout << YELLOW << "---------Test ShrubberyCreationForm---------------" << RESET << std::endl;
    std::cout << RED << "---------Failed TEST---------------" << RESET << std::endl;
    testShrubberyCreationForm(bur1);
    std::cout << GREEN << "-----------Passed-------------" << RESET << std::endl;
    testShrubberyCreationForm(bur2);
    std::cout << GREEN << "-----------Passed-------------" << RESET << std::endl;
    testShrubberyCreationForm(bur3);
    std::cout << YELLOW << "---------Test RobotomyRequestForm---------------" << RESET << std::endl;
    std::cout << RED << "---------Failed TEST---------------" << RESET << std::endl;
    testRobotomyRequestForm(bur1);
    std::cout << GREEN << "--------Passed SIGN--- " << RED "-----FAILED EXECUTE--------" << RESET << std::endl;
    testRobotomyRequestForm(bur2);
    std::cout << GREEN << "--------Passed----------------" << RESET << std::endl;
    testRobotomyRequestForm(bur3);
    std::cout << YELLOW << "---------Test PresidentialPardonForm---------------" << RESET << std::endl;
    std::cout << RED << "---------Failed TEST---------------" << RESET << std::endl;
    testPresidentialPardonForm(bur1);
    std::cout << RED << "--------Failed TEST----------------" << RESET << std::endl;
    testPresidentialPardonForm(bur2);
    std::cout << GREEN << "--------Passed----------------" << RESET << std::endl;
    testPresidentialPardonForm(bur3);
    std::cout << "------------------------" << std::endl;
    return 0;
}