/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 11:32:53 by relgheit          #+#    #+#             */
/*   Updated: 2025/12/04 12:40:23 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5){
    std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5), _target(target){
    std::cout << "PresidentialPardonForm Parameterized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : AForm(copy){
    this->_target = copy._target;
    std::cout << "PresidentialPardonForm Copy constructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
    AForm::operator=(other);
    this->_target = other._target;
    std::cout << "PresidentialPardonForm Assignment operator called" << std::endl;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
    std::cout << "PresidentialPardonForm Destructor called" << std::endl;
}

void PresidentialPardonForm::executeWork() const {
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}