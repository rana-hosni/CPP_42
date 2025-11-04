/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:05:32 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/04 14:46:02 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;
    std::string mood;
    
    std::cout << "Choose a mood: " << std::endl << "> I'm Harl" << std::endl << "> Programmed " << std::endl;
    
    std::getline(std::cin, mood);
    if (mood == "Programmed")
    {
        for (int i = 0; i < 10; i++)
        {
            harl.complain("DEBUG");
            harl.complain("INFO");
            harl.complain("WARNING");
            harl.complain("ERROR");
        }
    }
    else if (mood == "I'm Harl")
    {
        while (1)
        {
            std::string level;
            std::cout << "Enter complaint level (DEBUG, INFO, WARNING, ERROR): ";
            std::getline(std::cin, level);
            if (level.empty() || std::cin.eof())
                break;
            harl.complain(level);
        }
        std::cout << "Exiting Harl mode." << std::endl;
    }
    else
    {
        std::cout << "Invalid input. Exiting program." << std::endl;
    }
    return 0;
}