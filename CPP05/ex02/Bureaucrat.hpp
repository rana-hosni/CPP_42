/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:34:01 by relgheit          #+#    #+#             */
/*   Updated: 2025/12/04 15:00:44 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include "AForm.hpp"


#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string& _name, int _grade);
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        const std::string& getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm(AForm& form);
        void executeForm(const AForm& form) const;
        
        class GradeTooLowException : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Grade is too low!";
            }
        };
        class GradeTooHighException : public std::exception
        {
            virtual const char* what() const throw()
            {
                return "Grade is too high!";
            }
        };
        
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif