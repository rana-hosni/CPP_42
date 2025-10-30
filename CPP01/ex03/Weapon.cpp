/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:43:42 by relgheit          #+#    #+#             */
/*   Updated: 2025/10/30 16:46:00 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->_type = type;
}

Weapon::~Weapon()
{
}
const std::string& Weapon::getType() const
{
    return this->_type;
}

void Weapon::setType(std::string newType)
{
    this->_type = newType;
    return;
}
