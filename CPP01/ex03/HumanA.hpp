/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:43:31 by relgheit          #+#    #+#             */
/*   Updated: 2025/10/30 17:35:29 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanA
{
    public:
        HumanA(std::string name, Weapon& weaponA);
        ~HumanA();
        void attack();


    private:
        std::string _name;
        Weapon& _weaponA;
        
    
};

#endif
