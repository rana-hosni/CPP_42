/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:30:41 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/21 15:22:15 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(): ScavTrap(), FragTrap(), _Name("Default_clap_name"){
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << CYAN << "DiamondTrap Default constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    :ScavTrap(name),
    FragTrap(name),
    _Name(name + "_clap_name")
{
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
    this->_attackDamage = FragTrap::_attackDamage;
    std::cout << CYAN << "DiamondTrap Parameterized constructor called" << RESET << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other): ScavTrap(other), FragTrap(other), _Name(other._Name){
    std::cout << CYAN << "DiamondTrap Copy constructor called" << RESET << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other){
    std::cout << CYAN << "DiamondTrap Copy assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        this->_Name = other._Name;
    }
    return *this;
}

DiamondTrap::~DiamondTrap(){
    std::cout << CYAN << "DiamondTrap Destructor called" <<  RESET << std::endl;
}

void DiamondTrap::attack(const std::string& target){
    ScavTrap::attack(target);
}