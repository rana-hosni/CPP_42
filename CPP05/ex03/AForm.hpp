/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:00:51 by relgheit          #+#    #+#             */
/*   Updated: 2025/12/04 12:20:01 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

class Bureaucrat;

class AForm {
    protected:
        const std::string _name;
        bool _signed;
        const int _signGrade;
        const int _execGrade;

    public:
        AForm();
        AForm(const std::string name, const int signGrade, const int execGrade);
        AForm(const AForm& copy);
        AForm& operator=(const AForm& other);
        virtual ~AForm();
        
        const std::string getName() const;
        const int getGradeToSign() const;
        const int getGradeToExec() const;
        bool getFormIsSigned() const;
        void setFormIsSigned(bool isSigned);
        void beSigned(const Bureaucrat& bureaucrat);
        void execute(Bureaucrat const & executor) const;
        
        virtual void executeWork() const = 0;

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

std::ostream& operator<<(std::ostream& os, const AForm& form);

#endif