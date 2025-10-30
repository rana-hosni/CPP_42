/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:43:37 by relgheit          #+#    #+#             */
/*   Updated: 2025/10/30 17:49:54 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB
{
    public:
        HumanB(std::string name);
        ~HumanB();
        void attack();
        void setWeapon(Weapon& weaponB);


    private:
        std::string _name;
        Weapon* _weaponB;
    
};

#endif