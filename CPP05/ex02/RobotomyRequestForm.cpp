/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:17:59 by relgheit          #+#    #+#             */
/*   Updated: 2025/12/04 15:24:57 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45){
    std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target){
    std::cout << "RobotomyRequestForm Parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copy) : AForm(copy){
    this->_target = copy._target;
    std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
    AForm::operator=(other);
    this->_target = other._target;
    std::cout << "RobotomyRequestForm Assignment operator called" << std::endl;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
    std::cout << "RobotomyRequestForm Destructor called" << std::endl;
}

void RobotomyRequestForm::executeWork() const {
    std::cout << "Bzzzzzz... Vrrrrrr... (drilling noises)" << std::endl;
    int number;
    number = std::rand();
    std::cout << "Random number generated: " << number << std::endl;
    if (number % 2 == 0) {
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "The robotomy on " << this->_target << " failed." << std::endl;
    }
    // std::cout << "Executing RobotomyRequestForm for target: " << this->_target << std::endl;
 
}