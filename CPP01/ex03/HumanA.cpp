/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:43:25 by relgheit          #+#    #+#             */
/*   Updated: 2025/10/30 17:48:46 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "Weapon.hpp"



HumanA::HumanA(std::string name, Weapon& weaponA):_weaponA(weaponA)
{
    this->_name = name;
}
HumanA::~HumanA()
{
    
}

void HumanA::attack()
{
    std::cout << this->_name << " attacks with their " << this->_weaponA.getType() << std:: endl;
}