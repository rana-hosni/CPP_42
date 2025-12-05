/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 04:38:24 by relgheit          #+#    #+#             */
/*   Updated: 2025/12/05 04:38:24 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern Default constructor called" << std::endl;
}

Intern::Intern(const Intern& copy) {
    (void)copy;
    std::cout << "Intern Copy constructor called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    std::cout << "Intern Assignment operator called" << std::endl;
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern Destructor called" << std::endl;
}

AForm *Intern::makeForm(const std::string name, const std::string target) {
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"};
    AForm* (Intern::*create[3])(const std::string&) = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm};
    for (int i = 0; i < 3; i++) {
        if (name == formNames[i]) {
            std::cout << "Intern creates " << name << " form." << std::endl;
            return (this->*create[i])(target);
        }
    }
    std::cout << "Intern could not find the form: " << name << std::endl;
    return nullptr;
}


AForm* Intern::createShrubberyCreationForm(const std::string& target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target) {
    return new PresidentialPardonForm(target);
}