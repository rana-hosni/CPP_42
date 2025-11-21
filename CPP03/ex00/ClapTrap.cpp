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
    std::cout << GREEN << "ClapTrap Default constructor called" << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name):_Name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
    std::cout << GREEN << "ClapTrap Parameterized constructor called" << RESET << std::endl;
}

ClapTrap::~ClapTrap(){
    std::cout << GREEN << "ClapTrap Destructor called" <<  RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other){
    std::cout << GREEN << "ClapTrap Copy constructor called" << RESET << std::endl;
    _Name = other._Name;
    _hitPoints = other._hitPoints;
    _energyPoints = other._energyPoints;
    _attackDamage = other._attackDamage;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other){
    std::cout << GREEN << "ClapTrap Copy assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        _Name = other._Name;
        _hitPoints = other._hitPoints;
        _energyPoints = other._energyPoints;
        _attackDamage = other._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target){
    if (_energyPoints <= 0 || _hitPoints <= 0)
    {
        std::cout << MAGENTA << "ClapTrap " << _Name << " has no energy points left to attack!" << RESET << std::endl;
        return;
    }
    else
    {
        std::cout << RED << "ClapTrap " << _Name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << RESET << std::endl;
        _energyPoints--;
    }
}

void ClapTrap::takeDamage(unsigned int amount){

    std::cout << YELLOW << "ClapTrap " << _Name << " takes " << amount << " points of damage!" << RESET << std::endl;
    if (amount >= _hitPoints)
    {
        _hitPoints = 0;
        std::cout << YELLOW << "ClapTrap " << _Name << " has been destroyed!" << RESET << std::endl;
    }
    else
    {
        _hitPoints -= amount;
        std::cout << YELLOW << "ClapTrap " << _Name << " now has " << _hitPoints << " hit points!" << RESET << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount){
    if (_energyPoints <= 0 || _hitPoints <= 0)
    {
        std::cout << MAGENTA << "ClapTrap " << _Name << " has no energy points left to repair!" << RESET << std::endl;
        return;
    }
    else{
        std::cout << BLUE << "ClapTrap " << _Name << " is repaired for " << amount << " points!" << RESET << std::endl;
        _hitPoints += amount;
        _energyPoints--;
        std::cout << BLUE << "ClapTrap " << _Name << " now has " << _hitPoints << " hit points!" << RESET << std::endl;
    }
}

void ClapTrap::printStats(){
    std::cout << CYAN << "ClapTrap Stats - Name: " << _Name << std::endl;
    std::cout  << "Hit Points: " << _hitPoints << std::endl;
    std::cout  << "Energy Points: " << _energyPoints << std::endl;
    std::cout  << "Attack Damage: " << _attackDamage << RESET << std::endl;
}