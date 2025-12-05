/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:03:19 by relgheit          #+#    #+#             */
/*   Updated: 2025/12/04 14:39:25 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(): _signed(false), _signGrade(150), _execGrade(150){
    std::cout << "Form Default constructor called" << std::endl;
}

AForm::AForm(const std::string name,const int signGrade, const int execGrade):
    _signed(false), _name(name), _signGrade(signGrade), _execGrade(execGrade){
        if (signGrade < 1 || execGrade < 1)
            throw GradeTooHighException();
        else if (signGrade > 150 || execGrade > 150)
            throw GradeTooLowException();
        std::cout << "Form Parameterized constructor called" << std::endl;
}

AForm::AForm(const AForm& copy):
    _signed(copy._signed), _name(copy._name),
    _signGrade(copy._signGrade), _execGrade(copy._execGrade){
    std::cout << "Form Copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm& other){
    if (this != &other)
        this->_signed = other._signed;
    std::cout << "Form Assignment operator called" << std::endl;
    return *this;
}

AForm::~AForm(){
    std::cout << "Form Destructor called" << std::endl;
}

const std::string AForm::getName() const{
    return this->_name;
}

const int AForm::getGradeToSign() const{
    return this->_signGrade;
}

const int AForm::getGradeToExec() const{
    return this->_execGrade;
}

bool AForm::getFormIsSigned() const{
    return this->_signed;
}

void AForm::setFormIsSigned(bool isSigned){
    this->_signed = isSigned;
}

void AForm::beSigned(const Bureaucrat& bureaucrat){
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _signed = true;
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!this->getFormIsSigned())
        throw GradeTooLowException();
    if (executor.getGrade() > this->getGradeToExec())
        throw GradeTooLowException();
    executeWork();
}

std::ostream& operator<<(std::ostream& os, const AForm& form) {
    os << "Form name is: " << form.getName() << std::endl << 
    "Grade to be signed is: " << form.getGradeToSign() << std::endl <<
    "Grade to be executed is: " << form.getGradeToExec() << std::endl;
    if (form.getFormIsSigned())
        os << "Form is signed." << std::endl;
    else
        os << "Form is not signed." << std::endl;
    return os;
}