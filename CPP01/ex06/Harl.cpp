/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:05:48 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/04 15:18:48 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

int Harl::filterLevel(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    for (int i = 0; i < 4; i++)
    {
        if (level == levels[i])
            return i;
    }
    return -1;
}

void Harl::complain( std::string level )
{
    void (Harl::*functions[4])() = {&Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error};

    int levelIndex = filterLevel(level);
    
    switch (levelIndex)
    {
    case 0:
        (this->*functions[0])();
    case 1:
        (this->*functions[1])();
    case 2:
        (this->*functions[2])();
    case 3:
        (this->*functions[3])();
        break;
    
    default:
        std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
    
}

void Harl::debug( void )
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info( void )
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning( void )
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error( void )
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
