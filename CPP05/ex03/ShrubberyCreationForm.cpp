/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 10:31:28 by relgheit          #+#    #+#             */
/*   Updated: 2025/12/04 15:14:54 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137){
    std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){
    std::cout << "ShrubberyCreationForm Parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy) : AForm(copy){
    this->_target = copy._target;
    std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
    AForm::operator=(other);
    this->_target = other._target;
    std::cout << "ShrubberyCreationForm Assignment operator called" << std::endl;
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

void ShrubberyCreationForm::executeWork() const{
    std::fstream outfile;
    outfile.open(this->_target + "_shrubbery", std::ios::out | std::ios::trunc);
    if (!outfile.is_open()) {
        std::cerr << "Error: Could not open file " << this->_target + "_shrubbery" << std::endl;
        return;
    }
    outfile << "       _-_\n"
               "    /~~   ~~\\\n"
               " /~~         ~~\\\n"
               "{               }\n"
               " \\  _-     -_  /\n"
               "   ~  \\\\ //  ~\n"
               "_- -   | | _- _\n"
               "  _ -  | |   -_\n"
               "      // \\\\\n";
    outfile.close();
    std::cout << "Executing ShrubberyCreationForm for target: " << this->_target << std::endl;
    
}