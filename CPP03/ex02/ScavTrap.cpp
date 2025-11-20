/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 18:20:33 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/19 18:20:33 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap():ClapTrap(){
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << GREEN << "ScavTrap Default constructor called" << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
    std::cout << GREEN << "ScavTrap Parameterized constructor called" << RESET << std::endl;
}

ScavTrap::~ScavTrap(){
    std::cout << GREEN << "ScavTrap Destructor called" <<  RESET << std::endl;
}

void ScavTrap::attack(const std::string& target){
    if (_energyPoints <= 0 || _hitPoints <= 0)
    {
        std::cout << MAGENTA << "ScavTrap " << _Name << " has no energy points left to attack!" << RESET << std::endl;
        return;
    }
    else
    {
        std::cout << RED << "ScavTrap " << _Name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
        _energyPoints--;
    }
}

void ScavTrap::guardGate(){
    std::cout << ORANGE << "ScavTrap " << _Name << " is now in Gate keeper mode." << RESET << std::endl;
}