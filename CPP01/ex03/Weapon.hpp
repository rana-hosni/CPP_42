/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 13:43:45 by relgheit          #+#    #+#             */
/*   Updated: 2025/10/30 16:45:48 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
    public:
        Weapon(std::string type);
        ~Weapon();
        const std::string& getType() const;
        void setType(std::string newType);

    private:
        std::string _type;
};


#endif
    
