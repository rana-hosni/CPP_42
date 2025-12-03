/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:03:19 by relgheit          #+#    #+#             */
/*   Updated: 2025/12/03 14:26:38 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(): _signed(false), _signGrade(150), _execGrade(150){
    std::cout << "Form Default constructor called" << std::endl;
}

Form::Form(const std::string name,const int signGrade, const int execGrade):
    _signed(false), _name(name), _signGrade(signGrade), _execGrade(execGrade){
        if (signGrade < 1 || execGrade < 1)
            throw GradeTooHighException();
        else if (signGrade > 150 || execGrade > 150)
            throw GradeTooLowException();
        std::cout << "Form Parameterized constructor called" << std::endl;
}

Form::Form(const Form& copy):
    _signed(copy._signed), _name(copy._name),
    _signGrade(copy._signGrade), _execGrade(copy._execGrade){
    std::cout << "Form Copy constructor called" << std::endl;
}

Form& Form::operator=(const Form& other){
    if (this != &other)
        this->_signed = other._signed;
    std::cout << "Form Assignment operator called" << std::endl;
    return *this;
}

Form::~Form(){
    std::cout << "Form Destructor called" << std::endl;
}

const std::string Form::getName() const{
    return this->_name;
}

const int Form::getGradeToSign() const{
    return this->_signGrade;
}

const int Form::getGradeToExec() const{
    return this->_execGrade;
}

bool Form::getFormIsSigned() const{
    return this->_signed;
}

void Form::setFormIsSigned(bool isSigned){
    this->_signed = isSigned;
}

void Form::beSigned(const Bureaucrat& bureaucrat){
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _signed = true;
}

std::ostream& operator<<(std::ostream& os, const Form& form) {
    os << "Form name is: " << form.getName() << std::endl << 
    "Grade to be signed is: " << form.getGradeToSign() << std::endl <<
    "Grade to be executed is: " << form.getGradeToExec() << std::endl;
    if (form.getFormIsSigned())
        os << "Form is signed.";
    else
        os << "Form is not signed.";
    return os;
}