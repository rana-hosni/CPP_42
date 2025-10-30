/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:43:34 by relgheit          #+#    #+#             */
/*   Updated: 2025/10/30 17:47:59 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"


HumanB::HumanB(std::string name)
{
    this->_name = name;

}

HumanB::~HumanB()
{
    
}

void HumanB::attack()
{
    std::cout << this->_name << " attacks with their " << _weaponB->getType() <<std:: endl;
}

void HumanB::setWeapon(Weapon& weaponB)
{
    this->_weaponB = &weaponB;
}