/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: relgheit <relgheit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 13:42:32 by relgheit          #+#    #+#             */
/*   Updated: 2025/11/06 11:13:34 by relgheit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>



class Zombie 
{
    public: 
        Zombie(std::string name);
        ~Zombie();
        void announce( void );
    
    private:
        std::string name;
};


#endif
