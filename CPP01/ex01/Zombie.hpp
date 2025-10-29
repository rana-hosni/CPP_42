/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:09:46 by relgheit          #+#    #+#             */
/*   Updated: 2025/10/29 17:27:33 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP


#include <iostream>


class Zombie 
{
    public: 
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void announce( void );
        void setName(std::string name);
    
    private:
        std::string name;
};

Zombie* zombieHorde( int N, std::string name );

#endif