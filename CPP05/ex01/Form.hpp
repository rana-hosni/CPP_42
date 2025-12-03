/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:00:51 by relgheit          #+#    #+#             */
/*   Updated: 2025/12/03 14:12:30 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class Form {
    private:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _execGrade;

    public:
        Form();
        Form(const std::string name, const int signGrade, const int execGrade);
        Form(const Form& copy);
        Form& operator=(const Form& other);
        ~Form();
        
        const std::string getName() const;
        const int getGradeToSign() const;
        const int getGradeToExec() const;
        bool getFormIsSigned() const;
        void setFormIsSigned(bool isSigned);
        void beSigned(const Bureaucrat& bureaucrat);

        class GradeTooHighException: public std::exception{
            virtual const char* what() const throw()
            {
                return "Grade is too high!";
            }
            
        };
        class GradeTooLowException: public std::exception{
            virtual const char* what() const throw()
            {
                return "Grade is too low!";
            }
        };
};

std::ostream& operator<<(std::ostream& os, const Form& form);

#endif