/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:33:31 by relgheit          #+#    #+#             */
/*   Updated: 2025/12/03 14:25:51 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"


int main()
{
    Bureaucrat bur1("John", 5);
    Form form1("BaseForm", 50, 30);
    Form form2("AnotherForm", 2, 20);
    std::cout << "------------------------" << std::endl;
    
    std::cout << "-------TEST Signed Form-------" << std::endl;
    bur1.signForm(form1);
    std::cout << form1 << std::endl;
    std::cout << "------------------------" << std::endl;
    
    std::cout << "-------TEST Unsigned Form-------" << std::endl;
    bur1.signForm(form2);
    std::cout << form2 << std::endl;
    std::cout << "------------------------" << std::endl;
    try{
        
        Form form("badForm", 160 , 100);
    }
    catch (const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    std::cout << "------------------------" << std::endl;
    return 0;
}