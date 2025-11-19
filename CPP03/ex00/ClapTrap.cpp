/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 10:41:11 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/19 10:41:11 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():_Name("Default"), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name):_Name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << "ClapTrap Parameterized constructor called" << std::endl;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap Destructor called" <<  std::endl;
}

void ClapTrap::attack(const std::string& target){
    std::cout << "ClapTrap " << _Name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){

    std::cout << "ClapTrap " << _Name << " takes " << amount << " points of damage!" << std::endl;
    if (amount >= _hitPoints)
    {
        _hitPoints = 0;
        std::cout << "ClapTrap " << _Name << " has been destroyed!" << std::endl;
    }
    else
    {
        _hitPoints -= amount;
        std::cout << "ClapTrap " << _Name << " now has " << _hitPoints << " hit points!" << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount){
    std::cout << "ClapTrap " << _Name << " is repaired for " << amount << " points!" << std::endl;
    _hitPoints += amount;
    std::cout << "ClapTrap " << _Name << " now has " << _hitPoints << " hit points!" << std::endl;
}